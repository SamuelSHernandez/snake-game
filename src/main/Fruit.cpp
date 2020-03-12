#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
#include "Snake.h"
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
    Point point;
    return point;
}
 void Fruit::spawnFruit(int mapHeight, int mapWidth) {
//     // if not in snake
//     // if not outside bounds
 }
 void Fruit::removeFruit(int mapHeight, int mapWidth) {
    if (true) {
    }  // if snake head position == fruit position, remove fruit
 }
