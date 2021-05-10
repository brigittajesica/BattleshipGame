#include "testingfunctions.h"

testingfunctions::testingfunctions()
{

}

int testingfunctions::getShipLength(char x){
    int length = 0;
    switch (x) {
    case 'a':
        length = 5;
        break;
    case 'b':
        length = 4;
        break;
    case 'c':
        length = 3;
        break;
    case 'd':
        length = 2;
        break;
    }
    return length;
}
