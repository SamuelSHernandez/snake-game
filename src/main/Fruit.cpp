#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void Fruit::setPosition(int mapHeight, int mapWidth, Point snakeHead) {
    do {
        int fruitX = rand() % (mapWidth - 2) - 1;   // Generates food at a random X position
        int fruitY = rand() % (mapHeight - 2) - 1;  // Generates food at a random Y position

        fruitPosition.x = fruitX;
        fruitPosition.y = fruitY;
    } while (!(fruitPosition == snakeHead));  // this will be to check if location is free or not later on
}

Point Fruit::getPosition() const {
    return fruitPosition;
}