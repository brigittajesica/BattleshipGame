#include "field.h"

std::ostream& operator<<(std::ostream& os, const Field& field) {
    os << '(';
    switch (field) {
    case Field::OCCUPIED:
        os << 'O';
        break;
    case Field::DESTROYED:
        os << 'X';
        break;
    case Field::EMPTY:
        os << ' ';
        break;
    }
    os << ')';
    return os;
}
