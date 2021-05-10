#include "shot.h"

std::ostream& operator<<(std::ostream& os,const Shot& shot) {
    os << '(';
    switch (shot) {
    case Shot::MISS:
        os << 'O';
        break;
    case Shot::HIT:
        os << 'X';
        break;
    case Shot::UNATTEMPTED:
        os << ' ';
        break;
    }
    os << ')';
    return os;
}
