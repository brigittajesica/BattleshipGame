#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include "shot.h"
#include "ship.h"
#include "shipboard.h"
#include "shotboard.h"

#define NUM_BATTLESHIPS 0
#define NUM_CRUISERS 0
#define NUM_DESTROYERS 1
#define NUM_SUBMARINES 1

/**
 * @brief A model for the player, who owns serveral ships and may shoot his opponent
 */
class Player
{

public:
    /**
     * @brief Constructs a new player without a name and 10 ships
     */
    Player();
    /**
     * @brief Constructs a new player with a name and 10 ships
     * @param name The name the player should initially have
     */
    Player(std::string name);
    /**
     * @brief Stores another player inside a std::weak_ptr
     * @param playerPtr A std::shared_ptr to any player, who sould be the opponent
     */
    void setOpponent(std::shared_ptr<Player> playerPtr);
    /**
     * @brief Retrieves the players ships
     */
    std::vector<Ship>& getShips();
    /**
     * @brief Retrieves the players shipBoard
     */
    ShipBoard& getShipBoard(); //TODO make const after placeShip is moved into Player
    /**
     * @brief Retrieves the players shotBoard
     */
    ShotBoard& getShotBoard();
    /**
     * @brief Sets the players name
     */
    void setName(std::string name);
    /**
     * @brief Retrieves the players name
     * @return The name of the player, or an empty string is no name has been set
     */
    std::string getName() const;
    /**
     * @brief Places shots on the player's opponent's shipBoard, if a opponent has been set
     * @param row The field to shoot on the y axis
     * @param col The field to shoot on the x axis
     */
    void shootOpponent(uint8_t row,uint8_t col);
    /**
     * @brief Checks if the player has lost the game
     * @return true if all of the player's ships have been destroyed, false otherwise
     */
    bool hasLost() const;
    /**
     * @brief Retrieves ships on the players shipBoard by position
     * @param row The position to look for on the y axis
     * @param col The position to look for on the x axis
     * @return A pointer to an instance of Ship or nulptr if no ship was located at the requested position
     */
    Ship* getShipByPosition(uint8_t row, uint8_t col);

private:
    std::weak_ptr<Player> opponentPtr;
    std::string name;
    std::vector<Ship> ships;
    ShipBoard shipBoard;
    ShotBoard shotBoard;

    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

};

#endif // PLAYER_H
