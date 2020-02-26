#include "Fruit.h"
#include <ctime>
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

void setPosition(int fruitX, int fruitY, int mapHeigth, int mapWidth) {
    do {
        fruitX = rand() % (mapWidth - 2) - 1;   // Generates food at a random X position
        fruitY = rand() % (mapHeigth - 2) - 1;  // Generates food at a random Y position

    } while (true);  // this will be to check if location is free or not later on
}

void getPosition(struct Point);
void spawnFruit() {
}
void removeFruit() {
}