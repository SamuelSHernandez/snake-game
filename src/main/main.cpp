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
#include <cassert>
#include <iostream>
#include "Fruit.h"
#include "Game.h"
#include "Player.h"
#include "Snake.h"
#include "Type.h"
using namespace std;

void test_main();

int main() {
    string name;
    char myChar;
    cout << "Game of snake " << endl;
    cout << "Enter your name:";
    cin >> name;

    Player *player = new Player(name);



    test_main();

    return 0;
}

void test_main() {
    // // testing gameLoop function
    Game mygame(1);
    cout << "about to run game loop" << endl;
    mygame.gameLoop();
}