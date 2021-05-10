#ifndef SHOT_H
#define SHOT_H

#include <iostream>

enum class Shot {
    UNATTEMPTED,
    HIT,
    MISS
};

std::ostream& operator<<(std::ostream& os,const Shot& shot);

#endif // SHOT_H
