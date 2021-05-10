#ifndef BATTLESHIPGUI_H
#define BATTLESHIPGUI_H

#include <QMainWindow>
#include <QHeaderView>
#include <shipboard.h>
#include <QTableView>
#include <QPushButton>
#include <player.h>
#include <game.h>

/**
 * @file battleshipgui.h
 * @brief GUI for battleship game
 */

/**
 * @brief Vector of Buttons, each indicating a ship that is to be placed
 */
extern std::vector<QPushButton *> buttonVec;

/**
 * @brief Counting the number of ships that are not yet placed in the board
 */
extern int restShip;

namespace Ui {
class BattleshipGUI;
}

/**
 * @brief instantiates BattleshipGUI, which inherits class QMainWindow
 */
class BattleshipGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleshipGUI(QWidget *parent = nullptr);
    ~BattleshipGUI();

private:
    Ui::BattleshipGUI *ui;
    /**
     * @brief Setup the size of column/row cells
     * @param *header, header of the model to be shown in the viewclass
     */
    void setupHeader(QHeaderView *header);

    /**
     * @brief Setup the View Class by setting the model to be shown
     * @param *pboard, pointer of the model to be shown
     * @param *pb, pointer of the view where model will be shown
     */
    void setupTableView(QAbstractTableModel *pboard, QTableView *pb);

    /**
     * @brief initializes all ships to be placed, sets which board is shown depending on the current player
     * @param player, the current player
     */
    void setupShips(std::shared_ptr<Player> player);

    /**
     * @brief place a ship (when the ship button is clicked) on the board (where the cell is clicked), also setup instructions displayed
     * @param player, the current player
     * @param i, the length of the ship currently being placed
     * @param *curButton, the ship button that is currently clicked (to be placed)
     */
    void buttonPlaceShip(std::shared_ptr<Player> player, size_t i, QPushButton * curButton);

    /**
     * @brief inserts the ship in the game to the vector of buttons (buttonVec)
     */
    void pushbackButton();

    /**
     * @brief Sets the instruction shown
     * @param player, the current player
     */
    void instruction(std::shared_ptr<Player> player);

    /**
     * @brief Updates all cells of the board
     * @param *pboard, the current board
     */
    void updateAllCell(QTableView *pboard);

    /**
     * @brief shows the GUI before start game is clicked
     */
    void startGameInit();

    /**
     * @brief shows the GUI after start game is clicked (with boards)
     */
    void startGame();

    /**
     * @brief the function when showButton is clicked. It shows the board(s) that the player who has its turn is allowed to see.
     * @param player, the player of the previous turn. (NOT current player)
     */
    void showButton(std::shared_ptr<Player> player);

    /**
     * @brief the function when doneButton is clicked. It hides all boards and switches the player from current player to the opponent.
     * @param player, the current player
     */
    void doneButton(std::shared_ptr<Player> player);

    /**
     * @brief rotate the ship. The part of the ship that is clicked becomes the anchor of the rotation
     * @param player, the current player
     * @param *curShipPtr, the ship that is clicked
     * @param *curIndex, the current index that is clicked (contains info of row and column)
     * @param newOrientation, the new orientation of the ship
     */
    void on_rotateButton_clicked(std::shared_ptr<Player> player, Ship *curShipPtr, QModelIndex curIndex, Ship::Orientation newOrientation);

    /**
     * @brief Moves a ship from a field in the board to another field that is clicked
     * @param player, the current player
     */
    void on_board_clicked_move(std::shared_ptr<Player> player);

    /**
     * @brief assigns a shot to the shotboard of the opponent (changing the color of the field)
     * @param player, the current player
     */
    void on_board_clicked_shot(std::shared_ptr<Player> player);

    /**
     * @brief instantiate a pointer of the class Player, called player1
     */
    std::shared_ptr<Player> player1;

    /**
     * @brief instantiate a pointer of the class Player, called player2
     */
    std::shared_ptr<Player> player2;

    /**
     * @brief gives information on the phase of the game. (0 = placing ships, 1 = ship is placed, shooting)
     */
    int gamePhase;

    /**
     * @brief gives information on if a ship is rotated or not
     */
    bool rotated;

    /**
     * @brief an instance of the class Game
     */
    Game *game;
};

#endif // BATTLESHIPGUI_H
