#include "ship.h"
#include <string>

Ship::Ship(const Type t): type(t) {};

uint8_t Ship::getSize() const {
    return static_cast<uint8_t>(type);
}

std::string Ship::getTypeStr() const {
    switch(type){
    case Ship::Type::BATTLESHIP:
        return "Battleship";
    case Ship::Type::CRUISER:
        return "Cruiser";
    case Ship::Type::DESTROYER:
        return "Destroyer";
    default:
        return "Submarine";
    }
}

position Ship::getPosition() const {
    return startPos;
}

void Ship::setPosition(const u_int8_t col, const uint8_t row, const Orientation o) {
    startPos.col = col;
    startPos.row = row;
    orientation = o;
}

Ship::Orientation Ship::getOrientation() const {
    return this->orientation;
}

bool Ship::isDestroyed() const {
    if(occupied.empty()) {
        return false;
    }
    for(Field* field : occupied) {
        if(*field != Field::DESTROYED) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream& os, Ship::Type type) {
    switch (type) {
    case Ship::Type::BATTLESHIP:
        os << "Battleship";
        break;
    case Ship::Type::CRUISER:
        os << "Cruiser";
        break;
    case Ship::Type::DESTROYER:
        os << "Destroyer";
        break;
    case Ship::Type::SUBMARINE:
        os << "Submarine";
        break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Ship::Orientation& orientation) {
    char orientationSwitch;
    is >> orientationSwitch;
    if (orientationSwitch == 'H' || orientationSwitch == 'h') {
        orientation = Ship::Orientation::HORIZONTAL;
    } else {
        orientation = Ship::Orientation::VERTICAL;
    }
    return is;
}


std::ostream &operator<<(std::ostream& os, Ship& ship) {
    os << ship.type << " (" << static_cast<int>(ship.getSize()) << " fields)";
    return os;
}
