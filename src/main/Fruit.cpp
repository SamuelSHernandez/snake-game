#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

Fruit::Fruit() {
}
void Fruit::setPosition(int mapHeight, int mapWidth) {
    do {
        int fruitX = rand() % (mapWidth - 2) - 1;   // Generates food at a random X position
        int fruitY = rand() % (mapHeight - 2) - 1;  // Generates food at a random Y position

        Point fruitPoint;
        fruitPoint.x = fruitX;
        fruitPoint.y = fruitY;
    } while (true);  // this will be to check if location is free or not later on
}

Point Fruit::getPosition() const {
    Point point;
    return point;
}
void Fruit::spawnFruit(int mapHeight, int mapWidth) {
}
void Fruit::removeFruit(int mapHeight, int mapWidthe) {
}