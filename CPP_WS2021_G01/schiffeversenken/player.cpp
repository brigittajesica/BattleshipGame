#include "player.h"

Player::Player()
{

    for(u_int8_t i = 0; i < NUM_BATTLESHIPS; i++) {
        Ship* battleship = new Ship(Ship::Type::BATTLESHIP);
        ships.push_back(*battleship);
    }

    for(uint8_t i = 0; i < NUM_CRUISERS; i++) {
        Ship* cruiser = new Ship(Ship::Type::CRUISER);
        ships.push_back(*cruiser);
    }

    for(uint8_t i = 0; i < NUM_DESTROYERS; i++) {
        Ship* destroyer = new Ship(Ship::Type::DESTROYER);
        ships.push_back(*destroyer);
    }

    for(uint8_t i = 0; i < NUM_SUBMARINES; i++) {
        Ship* submarine = new Ship(Ship::Type::SUBMARINE);
        ships.push_back(*submarine);
    }

}

Player::Player(const std::string name): Player() {
    this->name = name;
}

void Player::setName(std::string name){
    this->name = name;
}

std::string Player::getName() const {
    return (name.empty())? "" : this->name;
}

void Player::setOpponent(const std::shared_ptr<Player> playerPtr) {
    this->opponentPtr = playerPtr;
}

std::vector<Ship>& Player::getShips() {
    return this->ships;
}

ShipBoard& Player::getShipBoard() {
    return this->shipBoard;
}

ShotBoard& Player::getShotBoard() {
    return this->shotBoard;
}

void Player::shootOpponent(const uint8_t row, const uint8_t col) {
    if( col>=BOARD_WIDTH || row>=BOARD_HEIGHT ) {
        std::cerr << "Cannot shoot outside the board!" << std::endl;
        return;
    }
    if(auto opponent = opponentPtr.lock()) {
        Field& target = opponent->shipBoard.fields[row][col];
        if(target != Field::EMPTY) {
            std::cout << "HIT!" << std::endl;
            target = Field::DESTROYED;
            shotBoard.shots[row][col] = Shot::HIT;
        } else {
            std::cout << "MISS!" << std::endl;
            shotBoard.shots[row][col] = Shot::MISS;
        }
        return;
    }
    std::cout << this->name << " has no opponent." << std::endl;
}

bool Player::hasLost() const {
    for(Ship ship : this->ships) {
        if(ship.isDestroyed() == false) {
            return false;
        }
    }
    return true;
}

Ship* Player::getShipByPosition(const uint8_t row,const uint8_t col) {
    Field* fieldPtr = &this->shipBoard.fields[row][col];
    for(Ship& ship : this->ships) {
        auto search = ship.occupied.find(fieldPtr);
        if(search != ship.occupied.end()) {
            return &ship;
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, std::vector<Ship>& ships) {
    std::cout << "Available Ships:" << std::endl;
    for(Ship ship : ships) {
        os << ship  << std::endl;
    };
    return os;
}

std::istream& operator>>(std::istream& is, Player& player) {
    std::cout << "\n\n\n\n\n\n\n\n\t\t\t" << player.name << ", what is your name?\n\t\t\t";
    std::flush(std::cout);
    std::string name;
    is >> name;
    player.setName(name);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "\t\t\t\t" << player.getName() << std::endl;
    os << "" << std::endl;
    os << "Ships:\t\t\t\t\tShots:" << std::endl;
    for(uint8_t i = 0; i < BOARD_HEIGHT; i++) {
        auto& shipsRow = player.shipBoard.fields[i];
        auto& shotsRow = player.shotBoard.shots[i];
        os << shipsRow << "\t\t" << shotsRow << std::endl;
    }
    os << std::endl;
    return os;
}
