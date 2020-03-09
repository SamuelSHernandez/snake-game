/*************************************************************************
 *
 * Project III: Start here.
 *
 * File Name:       main.cpp
 * Name(s):         ?
 * Course:          CPTR 142
 * Date:            ?
 *
 */
#include <iostream>
#include "Fruit.h"
#include "Game.h"
#include "Player.h"
#include "Snake.h"
#include "Type.h"
using namespace std;

void test_main();

int main() {
    test_main();

    return 0;
}

void test_main() {
    // // testing gameLoop function
    Game mygame;
    // mygame.gameLoop();

    // testing type.h
    Point point;
    point.x = 3;
    point.y = 4;
    cout << point.x << endl << point.y << endl;

    mygame.render();

    Compass compass;
    compass = NORTH;
    cout << compass << endl;
}