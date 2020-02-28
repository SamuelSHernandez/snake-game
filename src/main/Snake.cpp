#include "Snake.h"

Snake::Snake() {

}

void Snake::changeDirection(Compass direction) { 
    
}

void Snake::lengthen() {

}

Point Snake::return_head() {
    return headPosition;
}

char Snake::move() { // This assumes board is oriented as a Cartesian coordinate system
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
