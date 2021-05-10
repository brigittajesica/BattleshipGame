#ifndef FIELD_H
#define FIELD_H

#include <iostream>

/**
 * @file field.h
 * @brief Possible values for fields in ShipBoard::fields
 */
enum class Field {
    EMPTY,          /**< The field is not occupied by a ship */
    OCCUPIED,       /**< The field is occupied by a ship */
    DESTROYED       /**< The field was occupied by a ship, but later shot and destroyed */
};

std::ostream& operator<<(std::ostream& os, const Field& field);

#endif // FIELD_H
