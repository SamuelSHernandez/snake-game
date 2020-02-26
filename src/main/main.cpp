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
using namespace std;

int main() {
    // testing gameLoop function
    Game mygame(10, 10);
    mygame.gameLoop();

    return 0;
}