#ifndef SHOTBOARD_H
#define SHOTBOARD_H

#include <QObject>
#include <QAbstractTableModel>
#include <array>
#include "board.h"
#include "shot.h"

class Player; //forward declaration of player for use with friend keyword

/**
 * @brief a model of the players board
 * @implements QAbstractTableModel for use with a QTableView
 */
class ShotBoard : public QAbstractTableModel
{
    Q_OBJECT

public:

    /**
     * @brief initializes an empty board of shots
     */
    ShotBoard();
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

private:
    std::array<std::array<Shot, BOARD_WIDTH>, BOARD_HEIGHT> shots;

    friend std::ostream& operator<<(std::ostream& os, const ShotBoard& board);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend Player;

};

std::ostream& operator<<(std::ostream& os, const std::array<Shot, BOARD_WIDTH>& row);

#endif // SHOTBOARD_H
