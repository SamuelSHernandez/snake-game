#include "Snake.h"

Snake::Snake(char ascii) {
    length = 2;
    this->ascii = ascii;
}

void Snake::lengthen() {
    length += 1;
}

void Snake::move() {  // This assumes board is oriented as a Cartesian coordinate system
    if (direction == NORTH) {
        headPosition.y -= 1;
    } else if (direction == EAST) {
        headPosition.x += 1;
    } else if (direction == SOUTH) {
        headPosition.y += 1;
    } else if (direction == WEST) {
        headPosition.x -= 1;
    }
}
