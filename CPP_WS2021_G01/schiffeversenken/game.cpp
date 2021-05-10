#include "game.h"
#include <iostream>

Game::Game(){
    player1 = std::make_shared<Player>("Player1");
    player2 = std::make_shared<Player>("Player2");
    player1->setOpponent(player2);
    player2->setOpponent(player1);
    currPlayer = player1;
};

const std::shared_ptr<Player> Game::getCurrentPlayer() const {
    return currPlayer;
}

const std::shared_ptr<Player> Game::getPlayer1() const {
    return player1;
}

const std::shared_ptr<Player> Game::getPlayer2() const {
    return player2;
}

/**
 * Just a helper to clear the console
 */
void clear() {
    std::cout << "\x1B[2J\x1B[H";
    std::flush(std::cout);
}

bool Game::nextRound() {
    clear();
    if(player1->hasLost() || player2->hasLost()) {
        std::cout << "\u001b[0m" << "The game is over." << std::endl;
        return false;
    }
    if(currPlayer==player1) {
        currPlayer = player2;
        std::cout << "\u001b[31m";
    } else {
        currPlayer = player1;
        std::cout << "\u001b[32m";
    }
    return true;
}

const std::shared_ptr<Player> Game::getWinner() const {
    if(player1->hasLost()) {
        return player2;
    }
    if(player2->hasLost()) {
        return player1;
    }
    return nullptr;
}

/**
 * Just a helper to reduce duplicate code for placing ships
 */
void placeShips(const std::shared_ptr<Player> player) {
    ShipBoard& board = player->getShipBoard();
    for(Ship& ship : player->getShips()) {
        int row, col;
        Ship::Orientation orientation;
        do {
            clear();
            std::cout << *player;
            std::cout << "Please place your " << ship << "." << std::endl;
            std::cout << "Row? (0-" << BOARD_HEIGHT-1 << ")" << std::endl;
            std::cin >> row;
            std::cout << "Column? (0-" << BOARD_WIDTH-1 << ")" << std::endl;
            std::cin >> col;
            std::cout << "Orientation? (V/h)" << std::endl;
            std::cin >> orientation;
        }
        while (board.placeShip(ship, row, col, orientation) == false);
    }
}

void Game::startCli() {
    currPlayer = player2;
    nextRound();
    std::cin >> *currPlayer;
    placeShips(currPlayer);
    nextRound();
    std::cin >> *currPlayer;
    placeShips(currPlayer);
    while(nextRound()) {
        std::cout << "\n\n\n\n\n\n\n\n\n\t\tReady, " << currPlayer->getName() << "? Press return to continue...";
        std::flush(std::cout);
        std::cin.ignore();
        std::cin.clear();
        std::cin.ignore(1);
        clear();
        std::cout << *currPlayer;
        int row, col;
        std::cout << "Where do you want to shoot?" << std::endl;
        std::cout << "Row? (0-" << BOARD_HEIGHT-1 << ")" << std::endl;
        std::cin >> row;
        std::cout << "Column? (0-" << BOARD_WIDTH-1 << ")" << std::endl;
        std::cin >> col;
        currPlayer->shootOpponent(row, col);
    }
    std::cout << getWinner()->getName() << " has won the game!" << std::endl;
}
