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

// void test_main();

int main() {  // add exception try/catch
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
        if (isdigit(snakeChar)) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "Invalid entry.";
            cout << "Please enter a valid character." << endl;
            cout << endl;
            snakeChar = '*';
            continue;
        }
    } while (snakeChar);
    
    Player(playerName, snakeChar);

    // Game difficulty and run game
    do {
        cout << "Choose a game difficulty (1), (2), or (3)" << endl;
        cout << "\t 1. Easy " << endl;
        cout << "\t 2. Medium " << endl;
        cout << "\t 3. Hard " << endl;
        cout << "Enter your choice: ";
        cin >> menuOption;
        try {
            Game myGame(menuOption); // throwing an exception here if (!cin) terminates the program.  It should simply 
                                    // clear cin and then run the menu again.
            myGame.gameLoop();
        }
        catch (runtime_error &except) {
            cout << except.what() << endl;
            
        }
    } while (menuOption);

    // test_main();
    return 0;
}

// void test_main() {
//     // testing gameLoop function
//     Game mygame(1);
//     cout << "about to run game loop" << endl;
//     mygame.gameLoop();
// }