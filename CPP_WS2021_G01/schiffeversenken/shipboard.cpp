#include "shipboard.h"
#include <array>
#include <QColor>
#include "field.h"

ShipBoard::ShipBoard() {
    for(auto& row : fields) {
        for (Field& col : row) {
            col = Field::EMPTY;
        }
    };
}

int ShipBoard::rowCount(const QModelIndex &parent) const {
    (void)parent;
    return BOARD_HEIGHT;
}

int ShipBoard::columnCount(const QModelIndex &parent) const {
    (void)parent;
    return BOARD_WIDTH;
}

QVariant ShipBoard::data(const QModelIndex &index, int role) const {
    if (role == Qt::BackgroundRole) {
        int row = index.row();
        int col = index.column();
        Field field = fields[row][col];
        //default color is gray
        QColor bg = QColor(Qt::gray); //TODO set color of cell based on value of field?

        //if ship than green(?)
        if(field == Field::OCCUPIED){
            bg = QColor(Qt::darkGreen);
        } else if(field == Field::DESTROYED){
            bg = QColor(Qt::darkRed);
        }
        return bg;
    }
    return QVariant();
}

bool ShipBoard::placeShip(Ship& ship, int row, int col, const Ship::Orientation orientation) {
    std::set<Field*>& currentPosition = ship.occupied;
    std::set<Field*> newPosition;
    for (uint8_t i=0; i < ship.getSize(); i++) {
        if( col>=BOARD_WIDTH || row>=BOARD_HEIGHT ) {
            std::cerr << "The ship cannot overlap board!" << std::endl;
            return false;
        }
        Field& newField = fields[row][col];
        if(newField == Field::OCCUPIED) {
            //the field is already occupied
            auto search = currentPosition.find(&newField);
            if(search == currentPosition.end()) {
                //new field is occupied by another ship
                std::cerr << "The ship cannot be placed there! The space is already in use." << std::endl;
                return false;
            }
        }
        newPosition.insert(&newField);
        if(orientation == Ship::Orientation::VERTICAL) {
            row++;
        } else {
            col++;
        }
    }
    for(Field* currFieldPtr : currentPosition) {
        *currFieldPtr = Field::EMPTY;
    }
    for(Field* newFieldPtr : newPosition) {
        *newFieldPtr = Field::OCCUPIED;
    }
    currentPosition = newPosition;
    ship.setPosition(col, row, orientation);
    return true;
}

std::ostream& operator<<(std::ostream& os, const ShipBoard& board) {
    os << "Your ships:" << std::endl;
    for(const auto& row : board.fields) {
        os << row << std::endl;
    };
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::array<Field, BOARD_WIDTH>& row) {
    for(const Field& field : row) {
        os << field;
    }
    return os;
}
