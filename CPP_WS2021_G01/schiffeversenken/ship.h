#ifndef SHIP_H
#define SHIP_H

#include <cstdint>
#include <set>
#include <memory>
#include <iostream>
#include "shot.h"
#include "field.h"

typedef struct {
    uint8_t col;
    uint8_t row;
} position;

class Player; //forward declaration of Player for use with friend keyword
class ShipBoard; //forward declaration of ShipBoard for use with friend keyword

/**
 * @brief A model of ships with different sizes, which a player can place on his board
 */
class Ship
{
public:
    /**
     * @brief Possible values for the orientation of a ship
     */
    enum class Orientation {
        HORIZONTAL,         /**< The ship spans over multiple columns */
        VERTICAL,           /**< The ship spans over multiple rows */
    };
    /**
     * @brief Possible types of ships, each of which takes up a certain amount of space
     */
    enum class Type: uint8_t {
        BATTLESHIP = 5,     /**< Battleships require 5 fields of space */
        CRUISER = 4,        /**< Cruisers require 4 fields of space */
        DESTROYER = 3,      /**< Destroyers require 3 fields of space */
        SUBMARINE = 2       /**< Subramines require 5 fields of space */
    };
    /**
     * @brief Initializes a new ship of the specified type
     * @param type The Ship::Type of ship to create
     */
    Ship(const Type type);
    /**
     * @brief Checks if the ship has been destroyed
     * @return true if all parts of the ship have been destroyed, false otherwise
     */
    bool isDestroyed() const;
    /**
     * @brief Get the size of the ship, which depends on it's Ship::type
     * @return The number of fileds this ship occupies
     */
    uint8_t getSize() const;
    /**
     * @brief Retrieves the current position of the ship
     * @return The upper left position of the ship
     */
    position getPosition() const;
    /**
     * @brief Retreives the current orientation of the ship
     */
    Orientation getOrientation() const;
    /**
     * @brief Retrieves a string representation of Ship::type
     */
    std::string getTypeStr() const;
    /**
     * @brief The type and therefore size of the ship
     */
    const Type type;

private:
    std::set<Field*> occupied;
    position startPos;
    Orientation orientation;

    /**
     * @brief Sets the position of the upper left field of the ship
     * @param col The column, the ship has been placed
     * @param row The row, the ship has been placed
     */
    void setPosition(const u_int8_t col, const uint8_t row, Orientation orientation);

    friend std::ostream &operator<<(std::ostream& os, Ship& ship);
    friend ShipBoard;
    friend Player;

};

std::istream& operator>>(std::istream& is, Ship::Orientation& orientation);

#endif // SHIP_H
