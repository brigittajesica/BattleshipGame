#ifndef SHIPBOARD_H
#define SHIPBOARD_H

#include <QObject>
#include <QAbstractTableModel>
#include <array>
#include "board.h"
#include "ship.h"
#include "field.h"
#include <QColor>

class Player; //forward declaration of player for use with friend keyword


/**
 * @brief A model of the players board of ships
 * @implements QAbstractTableModel for use with a QTableView
 */
class ShipBoard : public QAbstractTableModel
{
    Q_OBJECT

public:

    /**
     * @brief Initializes an empty board, i.e. all fields are of type Field::EMPTY
     */
    ShipBoard();
    /**
     * @copydoc QAbstractTableModel::rowCount()
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @copydoc QAbstractTableModel::columnCount()
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @copydoc QAbstractTableModel::data()
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * @brief places a ship on the board, so that the corresponding fields will be occupied
     * @param ship the instance of a ship to be placed
     * @param row postition of the ship on the y axis
     * @param col postition of the ship on the x axis
     * @param orientation horizontal or vertical
     * @return true if the ship has been placed, false otherwise
     */
    bool placeShip(Ship& ship, int row, int col,const Ship::Orientation orientation);

private:
    std::array<std::array<Field, BOARD_WIDTH>, BOARD_HEIGHT> fields;

    friend std::ostream& operator<<(std::ostream& os, const ShipBoard& board);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend Player;
};

std::ostream& operator<<(std::ostream& os, const std::array<Field, BOARD_WIDTH>& row);

#endif // SHIPBOARD_H
