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
#include "main_func.h"
using namespace std;

int main() {  // finish exception handling
    int menuOption;
    string playerName;
    char snakeChar;
    string snakeSkin;

    // Welcome
    cout << endl;
    cout << "============================================================================" << endl;
    cout << "|                               ASCII  SNAKE                               |" << endl;
    cout << "============================================================================" << endl;

    // Player's name
    cout << "Welcome! Please enter your name below. Make sure you spell it the same way " << endl;
    cout << "each time for score tracking. " << endl;
    playerName = getNameEntry();

    // Snake character
    cout << endl;
    do {
        cout << "Enter a single ASCII character that is not a number: ";
        cin >> snakeSkin;               // String user input to string
        snakeChar = snakeSkin.front();  // Assign first character of string

        if (isdigit(snakeChar) || (!cin)) {  // Error checking
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

        if (!cin) {  // Error checking
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "Invalid entry. ";
            cout << "Please enter a valid menu option." << endl;
            cout << endl;
            menuOption = 1;
            continue;
        } else {
            break;
        }

    } while (menuOption);

    // Create game object and opens storage files
    Game myGame(menuOption, snakeChar, playerName);
    try {
        myGame.loadStorage();
    } catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
    }

    // User must open board.txt, then press
    string trash;
    cout << endl << endl;
    cout << "Game Created. Use the w, a, s, and d keys to move your snake." << endl;
    cout << "Open the file \"Board.txt\" to play the game." << endl;
    system("read -p 'Press Enter To Continue...' var");
    cout << endl;
    cout << "============================================================================" << endl;
    cout << "Change direction: ";

    // Run Game
    myGame.gameLoop();

    // Prints game scores
    try {
        myGame.printStorage();
    } catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
    }

    // this MUST happen after data is stored
    myGame.printLeaderboard();

    return 0;
}
