#include "Fruit.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
#include "Snake.h"
using namespace std;

void Fruit::setPosition(int mapHeight, int mapWidth, Point snakeHead, int board[100][100]) {
    int fruitX;
    int fruitY;
    srand(time(NULL));
    do {
        fruitX = rand() % (mapWidth) + 1;   // Generates food at a random X position
        fruitY = rand() % (mapHeight) + 1;  // Generates food at a random Y position
    } while (board[fruitY][fruitX] > 0 || abs(snakeHead.x - fruitX) < 2 ||
             abs(snakeHead.y - fruitY) < 2);  // this will be to check if location is free or not later on
    fruitPosition.x = fruitX;
    fruitPosition.y = fruitY;
    board[fruitPosition.y][fruitPosition.x] = -3;
}

Point Fruit::getPosition() const {
    return fruitPosition;
}
