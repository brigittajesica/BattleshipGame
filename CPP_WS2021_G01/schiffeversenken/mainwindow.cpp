#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <list>
#include <iostream>
#include <stdlib.h>
#include "testingfunctions.h"

int curIndex = -1;
std::vector<s_range> shipList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    QPushButton::connect(ui->ship1, &QPushButton::clicked, this, [=](){this->MainWindow::on_commonButton_clicked(ui->ship1);});
    QPushButton::connect(ui->ship1_2, &QPushButton::clicked, this, [=](){this->MainWindow::on_commonButton_clicked(ui->ship1_2);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_player1board_cellClicked(int row, int column)
{
    if(ui->player1board->item(row, column) == NULL){
        ui->player1board->clearSelection();
        curIndex = -1;
    }
}

void MainWindow::on_ship_clicked(char shiptype)
{
    int shipLength = testingfunctions::getShipLength(shiptype);

    for(int i = 0; i < shipLength; i++){
        ui->player1board->setItem(0,i,new QTableWidgetItem);
        ui->player1board->item(0,i)->setBackground(Qt::red);
    }
    s_range *sr = new s_range;
    sr->coor1 = {0,0};
    sr->coor2 = {0, shipLength-1};
    shipList.push_back(*sr);
    delete sr;
    for (s_range &v : shipList){
        std::cout << "(" << v.coor1.first << ",";
        std::cout << v.coor1.second << "), ";
        std::cout << "(" << v.coor2.first << ",";
        std::cout << v.coor2.second << ")\n";
    }
}

int MainWindow::lookupShip(int sRow, int sColumn){
    if(ui->player1board->item(sRow, sColumn) == NULL)
        return -1;
    for(size_t i = 0; i < shipList.size(); i++){
        if(sRow >= shipList[i].coor1.first && sRow <= shipList[i].coor2.first && sColumn >= shipList[i].coor1.second && sColumn <= shipList[i].coor2.second)
            return i;
    }
    return -1;
}

void MainWindow::on_player1board_itemClicked(QTableWidgetItem *item)
{
    curIndex = lookupShip(item->row(), item->column());
    if(curIndex == -1) return;
    s_range v = shipList[curIndex];
    std::cout << "CURRENT SHIP: ";
    std::cout << "(" << v.coor1.first << ",";
    std::cout << v.coor1.second << "), ";
    std::cout << "(" << v.coor2.first << ",";
    std::cout << v.coor2.second << ")\n";
}


void MainWindow::on_rightButton_clicked()
{
    if (curIndex == -1)
        return;

    s_range curShip = shipList[curIndex];

    if(curShip.coor2.second == 9)
        return;
    for(int i = curShip.coor1.first; i <= curShip.coor2.first; i++)
        if(ui->player1board->item(i, curShip.coor2.second + 1) != NULL)
            return;

    shipList[curIndex].coor1 =  {curShip.coor1.first, curShip.coor1.second+1};
    shipList[curIndex].coor2 = {curShip.coor2.first, curShip.coor2.second+1};

    for(int i = curShip.coor1.first; i <= curShip.coor2.first; i++){
        ui->player1board->setItem(i, curShip.coor1.second, NULL);
            for(int k = curShip.coor1.second; k <= curShip.coor2.second; k++){
                ui->player1board->setItem(i,k+1,new QTableWidgetItem);
                ui->player1board->item(i,k+1)->setBackground(Qt::red);
            }
        }
    ui->player1board->clearSelection();
}

void MainWindow::on_leftButton_clicked()
{
    if (curIndex == -1)
        return;

    s_range curShip = shipList[curIndex];\

    if(curShip.coor1.second == 0)
        return;
    for(int i = curShip.coor1.first; i <= curShip.coor2.first; i++)
        if(ui->player1board->item(i, curShip.coor1.second - 1) != NULL)
            return;

    shipList[curIndex].coor1 = {curShip.coor1.first, curShip.coor1.second-1};
    shipList[curIndex].coor2 = {curShip.coor2.first, curShip.coor2.second-1};

    for(int i = curShip.coor1.first; i <= curShip.coor2.first; i++){
        ui->player1board->setItem(i, curShip.coor2.second, NULL);
            for(int k = curShip.coor1.second; k <= curShip.coor2.second; k++){
                ui->player1board->setItem(i,k-1,new QTableWidgetItem);
                ui->player1board->item(i,k-1)->setBackground(Qt::red);
            }
        }
    ui->player1board->clearSelection();
}

void MainWindow::on_upButton_clicked()
{
    //up button
    if (curIndex == -1)
        return;
    s_range curShip = shipList[curIndex];

    if(curShip.coor1.first == 0)
        return;
    for(int i = curShip.coor1.second; i <= curShip.coor2.second; i++)
        if(ui->player1board->item(curShip.coor1.first - 1, i) != NULL)
            return;


    shipList[curIndex].coor1 = {curShip.coor1.first-1, curShip.coor1.second};
    shipList[curIndex].coor2 = {curShip.coor2.first-1, curShip.coor2.second};;

    for(int i = curShip.coor1.second; i <= curShip.coor2.second; i++){
        ui->player1board->setItem(curShip.coor2.first, i, NULL);
            for(int k = curShip.coor1.first; k <= curShip.coor2.first; k++){
                ui->player1board->setItem(k-1,i,new QTableWidgetItem);
                ui->player1board->item(k-1,i)->setBackground(Qt::red);
            }
        }
    ui->player1board->clearSelection();
}

void MainWindow::on_downButton_clicked()
{
    //down button
    if (curIndex == -1)
        return;
    s_range curShip = shipList[curIndex];

    if(curShip.coor2.first == 9)
        return;
    for(int i = curShip.coor1.second; i <= curShip.coor2.second; i++)
        if(ui->player1board->item(curShip.coor2.first+1, i) != NULL)
            return;

    shipList[curIndex].coor1 = {curShip.coor1.first+1, curShip.coor1.second};
    shipList[curIndex].coor2 = {curShip.coor2.first+1, curShip.coor2.second};

    for(int i = curShip.coor1.second; i <= curShip.coor2.second; i++){
        ui->player1board->setItem(curShip.coor1.first, i, NULL);
            for(int k = curShip.coor1.first; k <= curShip.coor2.first; k++){
                ui->player1board->setItem(k+1,i,new QTableWidgetItem);
                ui->player1board->item(k+1,i)->setBackground(Qt::red);
            }
        }
    ui->player1board->clearSelection();
}

void MainWindow::on_rotateButton_clicked()
{
    if (curIndex == -1)
        return;

    s_range curShip = shipList[curIndex];
    bool isHorizontal = (curShip.coor1.first == curShip.coor2.first);

    int newHRow = curShip.coor1.first + (curShip.coor2.second - curShip.coor1.second);
    int newVColumn = curShip.coor1.second + (curShip.coor2.first - curShip.coor1.first);

    if(isHorizontal){
        for(int i = curShip.coor1.first+1; i <= newHRow; i++)
            if(i > 9 || i < 0 || ui->player1board->item(i, curShip.coor1.second) != NULL)
                return;
    } else {
        for(int i = curShip.coor1.second+1; i <= newVColumn; i++)
            if( i > 9 || i < 0 || ui->player1board->item(curShip.coor1.first, i) != NULL)
                return;
    }


    if(isHorizontal)
        shipList[curIndex].coor2 = {newHRow , curShip.coor1.second};
    else
        shipList[curIndex].coor2 = {curShip.coor1.first, newVColumn};

    //delete previous ship
    for(int i = curShip.coor1.first; i <= curShip.coor2.first; i++)
        for(int k = curShip.coor1.second; k <= curShip.coor2.second; k++){
            ui->player1board->setItem(i,k, NULL);
        }

    //set new rotated ship
    for(int i = shipList[curIndex].coor1.first; i <= shipList[curIndex].coor2.first; i++)
        for(int k = shipList[curIndex].coor1.second; k <= shipList[curIndex].coor2.second; k++){
            ui->player1board->setItem(i,k,new QTableWidgetItem);
            ui->player1board->item(i,k)->setBackground(Qt::red);
        }
    ui->player1board->clearSelection();
}

void MainWindow::on_commonButton_clicked(const QObject * sender)
{
    if(sender == ui->ship1){
        MainWindow::on_ship_clicked('c');
        ui->ship1->hide();
    }
    else if(sender == ui->ship1_2) {
        MainWindow::on_ship_clicked('a');
        ui->ship1_2->hide();
    }
}
