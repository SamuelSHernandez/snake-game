#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

Fruit::Fruit() {
}
void Fruit::setPosition(const Game &myGame) {
    do {
        int fruitX = rand() % (myGame.getMapWidth() - 2) - 1;   // Generates food at a random X position
        int fruitY = rand() % (myGame.getMapHeight() - 2) - 1;  // Generates food at a random Y position

        fruitPoint.x = fruitX;
        fruitPoint.y = fruitY;
    } while (true);  // this will be to check if location is free or not later on
}

Point Fruit::getPosition() const {
    Point point;
    return point;
}
void Fruit::spawnFruit() {
}
void Fruit::removeFruit() {
}