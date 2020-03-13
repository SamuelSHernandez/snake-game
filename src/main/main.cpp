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

int main() {  // finish exception handling
    int menuOption;
    string playerName;
    char snakeChar;

    // Player's name
    cout << "Enter your name: ";
    cin >> playerName;

    // Snake character
    do {
        cout << "Enter a single ASCII character that is not a number: ";
        cin >> snakeChar;
        if (isdigit(snakeChar) || !cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "Invalid entry. ";
            cout << "Please enter a valid character." << endl;
            cout << endl;
            snakeChar = '*';
            continue;
        } else {
            break;
        }
    } while (snakeChar);

    // Game difficulty and run game
    do {
        cout << endl << "Choose a game difficulty (1), (2), or (3)" << endl;
        cout << "\t 1. Easy " << endl;
        cout << "\t 2. Medium " << endl;
        cout << "\t 3. Hard " << endl;
        cout << endl << "Enter your choice: ";
        cin >> menuOption;

        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "Invalid entry.";
            cout << "Please enter a valid menu option." << endl;
            cout << endl;
            menuOption = 1;
            continue;
        } else {
            break;
        }
    } while (menuOption);

    Player myPlayer(playerName);
    Game myGame(menuOption, snakeChar);
    myGame.gameLoop();

    return 0;
}