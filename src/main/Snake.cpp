#include "Snake.h"

Snake::Snake() {
    length = 2;
}

void Snake::lengthen() {
    length += 1;
}

// Updates snake head position based on input direction
void Snake::move() {
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

void Snake::setAscii(char ascii) {
    this->ascii = ascii;
}