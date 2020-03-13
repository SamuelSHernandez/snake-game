#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
#include "Snake.h"
#include "ctime"
using namespace std;

void Fruit::setPosition(int mapHeight, int mapWidth, Point snakeHead, int board[100][100]) {
    do {
        srand(time(NULL));
        int fruitX = rand() % (mapWidth) + 1;   // Generates food at a random X position
        int fruitY = rand() % (mapHeight) + 1;  // Generates food at a random Y position

        fruitPosition.x = fruitX;
        fruitPosition.y = fruitY;

    } while (fruitPosition == snakeHead);  // this will be to check if location is free or not later on
    board[fruitPosition.y][fruitPosition.x] = -3;
}

Point Fruit::getPosition() const {
    return fruitPosition;
}
