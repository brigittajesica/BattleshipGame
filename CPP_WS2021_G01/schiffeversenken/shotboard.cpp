#include "shotboard.h"
#include <QColor>
#include <iostream>

ShotBoard::ShotBoard() {
    for(std::array<Shot, BOARD_WIDTH>& row : shots) {
        for (Shot& col : row) {
            col = Shot::UNATTEMPTED;
        }
    };
}

int ShotBoard::rowCount(const QModelIndex &parent) const {
    (void)parent;
    return BOARD_HEIGHT;
}

int ShotBoard::columnCount(const QModelIndex &parent) const {
    (void)parent;
    return BOARD_WIDTH;
}

QVariant ShotBoard::data(const QModelIndex &index, int role) const {
    if (role == Qt::BackgroundRole) {
        int row = index.row();
        int col = index.column();
        Shot shot = shots[row][col];

        switch(shot) {
        case Shot::HIT:
            return QColor(Qt::red);
        case Shot::MISS:
            return QColor(Qt::blue);
        default:
            return QColor(Qt::gray);
        }
    }
    return QVariant();
}

std::ostream& operator<<(std::ostream& os, const std::array<Shot, BOARD_WIDTH>& row) {
    for (const Shot& col : row) {
        os << col;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const ShotBoard& board) {
    os << "Your shots:" << std::endl << std::endl;
    for(const auto& row : board.shots) {
        os << row << std::endl;
    };
    return os;
}
