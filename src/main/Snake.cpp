#include "Snake.h"

Snake::Snake() {
}

Snake::Snake(char ascii, Compass compass, Point position) {
}

void Snake::lengthen() {
}

void Snake::move() {  // This assumes board is oriented as a Cartesian coordinate system
    if (direction == NORTH) {
        headPosition.y += 1;
    } else if (direction == EAST) {
        headPosition.x += 1;
    } else if (direction == SOUTH) {
        headPosition.y -= 1;
    } else if (direction == WEST) {
        headPosition.x -= 1;
    }
}
