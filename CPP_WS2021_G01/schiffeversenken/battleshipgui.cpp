#include "battleshipgui.h"
#include "ui_battleshipgui.h"
#include <shipboard.h>
#include <stdlib.h>
#include <player.h>
#include <QTableView>
#include <QHeaderView>
#include <ship.h>
#include <game.h>

std::vector<QPushButton *> buttonVec;
int restShip = 0;
bool rotated = false;
std::shared_ptr<Player> player1;
std::shared_ptr<Player> player2;
Game *game;


BattleshipGUI::BattleshipGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleshipGUI)
{
    ui->setupUi(this);
    BattleshipGUI::startGameInit();

    int gamePhase = 0;

    //Create Player 1 and Player 2
    game = new Game();
    player1 = game->getPlayer1();
    player2 = game->getPlayer2();

    //setup their board for the UI
    BattleshipGUI::setupTableView(&player1.get()->getShipBoard(), ui->player1board);
    BattleshipGUI::setupTableView(&player1.get()->getShotBoard(), ui->player1shotboard);
    BattleshipGUI::setupTableView(&player2.get()->getShipBoard(), ui->player2board);
    BattleshipGUI::setupTableView(&player2.get()->getShotBoard(), ui->player2shotboard);

    //player 1 setup ships with start game
    QPushButton::connect(ui->startgame, &QPushButton::clicked, this, [=](){this->BattleshipGUI::setupShips(player1);});
    QTableView::connect(ui->player1board, &QTableView::clicked, this, [=]{BattleshipGUI::on_board_clicked_move(player1);});
    QTableView::connect(ui->player2board, &QTableView::clicked, this, [=]{BattleshipGUI::on_board_clicked_move(player2);});
}

void BattleshipGUI::setupTableView(QAbstractTableModel *pboard, QTableView *pb){
    pb->setModel(pboard);
    pb->hide();
    BattleshipGUI::setupHeader(pb->verticalHeader());
    BattleshipGUI::setupHeader(pb->horizontalHeader());
}

void BattleshipGUI::setupHeader(QHeaderView *header){
    header->setSectionResizeMode(QHeaderView::Fixed);
    header->setDefaultSectionSize(22);
    header->hide();
}

void BattleshipGUI::setupShips(std::shared_ptr<Player> player){
    BattleshipGUI::pushbackButton();
    QTableView *pboard;
    if(player == player1){
        ui->player2board->hide();
        BattleshipGUI::startGame();
        pboard = ui->player1board;
        pboard->show();
        BattleshipGUI::showButton(player2);
    } else{
        pboard = ui->player2board;
    }
    restShip = player.get()->getShips().size();
    pboard->setStyleSheet("border: 3px solid lightgreen;");
}

void BattleshipGUI::buttonPlaceShip(std::shared_ptr<Player> player, size_t i, QPushButton * curButton){
    //init
    QTableView * pboard = (player == player1)? ui->player1board : ui->player2board;
    buttonVec[i]->setStyleSheet("Background-color: rgba(255,179,71,1); Text-align:left; color:black");
    BattleshipGUI::instruction(player);
    for(QPushButton *btn : buttonVec) {
        pboard->disconnect();
        btn->setDisabled(true);
    }
    //wait for a click signal from the table
    QEventLoop loop;
    QTableView::connect(pboard, &QTableView::clicked, &loop, &QEventLoop::quit);
    loop.exec();
    pboard->clearSelection();
    pboard->connect(pboard, &QTableView::clicked, this, [=]{BattleshipGUI::on_board_clicked_move(player);});

    QModelIndex curindex = pboard->currentIndex();
    if(player.get()->getShipBoard().placeShip(player.get()->getShips()[i], curindex.row(), curindex.column(), Ship::Orientation::HORIZONTAL)){
        //update all cell from table
        BattleshipGUI::updateAllCell(pboard);

        //hide ship button
        curButton->hide();
        for(QPushButton * btn : buttonVec){
                btn->setDisabled(false);
        }
        restShip-=1;
        if(restShip == 0) {
            pboard->setStyleSheet("");
            pboard->clearSelection();
            ui->doneButton->setDisabled(false);
            ui->showButton->setDisabled(true);
            ui->doneButton->disconnect();
            ui->showButton->disconnect();
            QPushButton::connect(ui->doneButton, &QPushButton::clicked, this, [=](){this->BattleshipGUI::doneButton(player);});
            QPushButton::connect(ui->showButton, &QPushButton::clicked, this, [=](){BattleshipGUI::showButton(player);});
            if(player == player2){
                ui->shipGroup->hide();
                }
        }
        return;
    }
    ui->instructions->setText("WARNING: The ship cannot overlap!");
    ui->instructions->setStyleSheet("color: red");
    buttonVec[i]->setStyleSheet("background-color: rgba(213, 50, 92, 0.8); Text-align:left;");
    for(QPushButton * btn : buttonVec){
            btn->setDisabled(false);
    }

}

void BattleshipGUI::on_board_clicked_shot(std::shared_ptr<Player> player){
    if(gamePhase == 0) return;
    QTableView *sboard = (player == player1)? ui->player1shotboard : ui->player2shotboard;
    QTableView *pboard = (player == player1)? ui->player2board : ui->player1board;
    QModelIndex curIndex = sboard->currentIndex();
    player.get()->shootOpponent(curIndex.row(), curIndex.column());
    BattleshipGUI::updateAllCell(sboard);
    BattleshipGUI::updateAllCell(pboard);
    sboard->disconnect();
    ui->doneButton->setDisabled(false);
    ui->showButton->setDisabled(true);
    ui->doneButton->disconnect();
    ui->doneButton->connect(ui->doneButton, &QPushButton::clicked, this, [=]{BattleshipGUI::doneButton(game->getCurrentPlayer());});
    sboard->clearSelection();
    pboard->clearSelection();
}

void BattleshipGUI::doneButton(std::shared_ptr<Player> player){
    ui->showButton->setDisabled(false);
    ui->doneButton->setDisabled(true);
    ui->rotateButton->hide();
    QTableView *pboard = (player == player1)? ui->player1board : ui->player2board;
    QTableView *sboard = (player == player1)? ui->player1shotboard : ui->player2shotboard;
    QLabel *oplabel = (player == player1)? ui->player2label : ui->player1label;
    pboard->hide();
    oplabel->show();
    if(player == player1){
        ui->player1label->hide();
        ui->instructions->setText(QString::fromStdString("INSTRUCTION:\n" + player1->getName() + " please look away. " + player2->getName() + ", if you're ready press SHOW"));
       if(gamePhase == 0) BattleshipGUI::setupShips(player2);
    } else {
        ui->player2label->hide();
        ui->instructions->setText(QString::fromStdString("INSTRUCTION:\n" + player2->getName() + " please look away. " + player1->getName() + ", if you're ready press SHOW"));
        if(gamePhase == 0) {
            //init game
            gamePhase += 1;
            return;
        }
    }
    if(gamePhase == 1){
        sboard->hide();
        oplabel->setText((player == player1)? QString::fromStdString(player2->getName()) : QString::fromStdString(player1->getName()));
        ui->showButton->disconnect();
        const std::shared_ptr<Player> temp = game->getCurrentPlayer();
        ui->showButton->connect(ui->showButton, &QPushButton::clicked, this, [=]{BattleshipGUI::showButton(temp);});
        if(!game->nextRound()){
            ui->doneButton->setDisabled(true);
            ui->showButton->setDisabled(true);
            ui->player1label->show();
            ui->player2label->show();
            ui->player1winlose->show();
            ui->player2winlose->show();
            ui->player1board->show();
            ui->player2board->show();
            if(player2->hasLost()){
                ui->player1winlose->setText("WIN!");
                ui->player1winlose->setStyleSheet("color: green;");
                ui->player2winlose->setText("LOSE!");
                ui->player2winlose->setStyleSheet("color: red;");
            } else {
                ui->player2winlose->setText("WIN!");
                ui->player2winlose->setStyleSheet("color: green;");
                ui->player1winlose->setText("LOSE!");
                ui->player1winlose->setStyleSheet("color: red;");
            }
        }
    }
}

void BattleshipGUI::showButton(std::shared_ptr<Player> player){
    std::shared_ptr<Player> p;
    QTableView *t;
    QTableView *sb;
    QLabel *plabel1;
    QLabel *plabel2;
    if(player == player1){
        t = ui->player2board;
        sb = ui->player2shotboard;
        plabel1 = ui->player2label;
        plabel2 = ui->player1label;
        p = player2;
        ui->rotateButton->move(ui->rotateButton->x()+430, ui->rotateButton->y());
    } else {
        t = ui->player1board;
        sb = ui->player1shotboard;
        plabel1 = ui->player1label;
        plabel2 = ui->player2label;
        p = player1;
        ui->rotateButton->move(ui->rotateButton->x()-430, ui->rotateButton->y());
    }
    BattleshipGUI::instruction(p);
    if(gamePhase == 0){
        ui->rotateButton->show();
        t->show();
        std::vector<Ship> ships = p.get()->getShips();
        for(size_t i = 0; i < ships.size(); i++){
            buttonVec[i]->setDisabled(false);
            buttonVec[i]->disconnect();
            buttonVec[i]->show();
            buttonVec[i]->resize(ships[i].getSize() * 26.5, 23);
            buttonVec[i]->setText(QString::fromStdString(ships[i].getTypeStr()));
            buttonVec[i]->setStyleSheet("background-color: rgba(213, 50, 92, 0.8); Text-align:left;");
            QPushButton::connect(buttonVec[i], &QPushButton::clicked, this, [=](){BattleshipGUI::buttonPlaceShip(p, i, buttonVec[i]);});
        }
    } else if(gamePhase == 1){
        t->clearSelection();
        t->setDisabled(true);
        sb->clearSelection();
        ui->showButton->setDisabled(true);
        t->disconnect();
        t->show();
        sb->show();
        plabel1->show();
        plabel2->show();
        plabel1->setText(QString::fromStdString(p->getName()));
        plabel2->setText("Shot Board");
        sb->disconnect();
        sb->connect(sb, &QTableView::clicked, this, [=]{BattleshipGUI::on_board_clicked_shot(p);});

    }
}


void BattleshipGUI::on_board_clicked_move(std::shared_ptr<Player> player)
{
    if(gamePhase == 1)
        return;
    QTableView *pboard = (player == player1)? ui->player1board : ui->player2board;
    QModelIndex ind = pboard->currentIndex();
    Ship *curShipPtr = player.get()->getShipByPosition(ind.row(), ind.column());
    if(curShipPtr != NULL){
        pboard->disconnect();
        ui->rotateButton->disconnect();
        ui->instructions->setText("Ship selected! Click anywhere to move your ship or click the rotate button to rotate the ship");
        ui->instructions->setStyleSheet("color: white;");
        Ship::Orientation curOrientation = (*curShipPtr).getOrientation();
        Ship::Orientation newOrientation = (curOrientation == Ship::Orientation::HORIZONTAL)? Ship::Orientation::VERTICAL : Ship::Orientation::HORIZONTAL;

        QPushButton::connect(ui->rotateButton, &QPushButton::clicked, this, [=]{
            BattleshipGUI::on_rotateButton_clicked(player, curShipPtr, ind, newOrientation);
        });

        //wait for another click, or rotate button
        QEventLoop loop;
        QPushButton::connect(ui->rotateButton, &QPushButton::clicked, &loop, &QEventLoop::quit);
        QTableView::connect(pboard, &QTableView::clicked, &loop, &QEventLoop::quit);
        loop.exec();

        //after loop
        pboard->connect(pboard, &QTableView::clicked, this, [=]{BattleshipGUI::on_board_clicked_move(player);});
        QModelIndex curIndex = pboard->currentIndex();
        pboard->clearSelection();

        if(rotated){
            ui->rotateButton->disconnect();
            rotated = false;
            return;
        }
        if(player.get()->getShipBoard().placeShip(*curShipPtr, curIndex.row(), curIndex.column(), curOrientation)){
            BattleshipGUI::updateAllCell(pboard);
        } else {
            ui->instructions->setText("WARNING: The ship cannot overlap!");
            ui->instructions->setStyleSheet("color: red");
        }
        ui->rotateButton->disconnect();
    }
    pboard->clearSelection();
    rotated = false;
}

void BattleshipGUI::on_rotateButton_clicked(std::shared_ptr<Player> player, Ship *curShipPtr, QModelIndex curIndex, Ship::Orientation newOrientation){
    rotated = true;
    if(player.get()->getShipBoard().placeShip(*curShipPtr, curIndex.row(), curIndex.column(), newOrientation)){
        BattleshipGUI::updateAllCell((player == player1)? ui->player1board : ui->player2board);
        ui->player1board->clearSelection();
        ui->player2board->clearSelection();
        ui->rotateButton->disconnect();
    } else {
        ui->instructions->setText("WARNING: The ship cannot overlap!");
        ui->instructions->setStyleSheet("color: red");
    }
}

void BattleshipGUI::startGameInit(){
    ui->startgame->move(280,290);
    ui->welcomeText->move(160, 150);
    ui->player1label->move(210, 205);
    ui->player2label->move(210, 240);
    ui->lineEdit1->move(330,210);
    ui->lineEdit2->move(330,245);
    ui->shipGroup->hide();
    ui->doneButton->setDisabled(true);
    ui->doneButton->hide();
    ui->showButton->hide();
    ui->player1winlose->hide();
    ui->player2winlose->hide();
    ui->rotateButton->hide();
}

void BattleshipGUI::startGame(){
    ui->startgame->move(20,20);
    ui->welcomeText->hide();
    ui->shipGroup->show();
    ui->startgame->setDisabled(true);
    ui->shipGroup->show();
    ui->doneButton->show();
    ui->showButton->show();
    ui->showButton->setDisabled(true);
    ui->doneButton->setDisabled(true);
    ui->player1label->show();
    ui->player1label->move(20, 380);
    player1->setName((ui->lineEdit1->text().toStdString() == "")? "Player 1" : ui->lineEdit1->text().toStdString());
    player2->setName((ui->lineEdit2->text().toStdString() == "")? "Player 2" : ui->lineEdit2->text().toStdString());
    ui->player1label->setText(QString::fromStdString(player1->getName()));
    ui->player2label->setText(QString::fromStdString(player2->getName()));
    ui->lineEdit1->hide();
    ui->lineEdit2->hide();
    ui->player2label->move(470, 380);
    ui->rotateButton->show();
    ui->player2label->hide();
}

void BattleshipGUI::instruction(std::shared_ptr<Player> player){
    std::string str = "INSTRUCTION:\n";
    str.append((player == player1)? player1->getName() : player2->getName());
    if(gamePhase == 0){
        str.append(" please set your ship, select a ship and click on the desired position.\nPress DONE when you're done");
    } else {
        str.append(" place your shot at the opponent's shot board!\nPress DONE when you're done");
    }
    ui->instructions->setText(QString::fromStdString(str));
    ui->instructions->setStyleSheet("color: white");
}

void BattleshipGUI::updateAllCell(QTableView *pboard){
    for(int row = 0; row < pboard->model()->rowCount(); row++)
        for(int col = 0; col < pboard->model()->columnCount(); col++)
            pboard->update(pboard->model()->index(row,col));
}

void BattleshipGUI::pushbackButton(){
    buttonVec.clear();
    buttonVec.push_back(ui->ship1);
    buttonVec.push_back(ui->ship2);
    buttonVec.push_back(ui->ship3);
    buttonVec.push_back(ui->ship4);
    buttonVec.push_back(ui->ship5);
    buttonVec.push_back(ui->ship6);
    buttonVec.push_back(ui->ship7);
    buttonVec.push_back(ui->ship8);
    buttonVec.push_back(ui->ship9);
    buttonVec.push_back(ui->ship10);
    for(QPushButton *pb : buttonVec){
        pb->hide();
    }
}

BattleshipGUI::~BattleshipGUI()
{
    delete ui;
}

