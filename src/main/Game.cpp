#include "Game.h"
#include <pthread.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char input = 's';
bool gameOver1 = false;
Game::Game() {
    // set map size based on gameDifficulty member variable
    switch (gameDifficulty) {
        case L_EASY:
            mapWidth = 10;
            mapHeight = 10;

            break;

        case L_MEDIUM:
            mapWidth = 15;
            mapHeight = 15;

            break;

        case L_HARD:
            mapWidth = 20;
            mapHeight = 20;

            break;
    }
    // sets the array with blank spaces with game difficulty size
    for (int i = 0; i < mapHeight + 2; ++i) {
        for (int j = 0; j < mapWidth + 2; ++j) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            if (i == 0 || i == mapHeight + 1) {
                board[i][j] = -1;
            } else if (j == 0 || j == mapWidth + 1) {
                board[i][j] = -2;
            }
        }
    }

    // Position snake
    gameSnake.setLength(2);
    gameSnake.setPosition(mapWidth - 1, mapHeight / 2);
    gameSnake.setAscii('=');
    board[mapHeight / 2][mapWidth] = 1;  // need to set tail in board first time
}
// Function to get User Input
void getUserInput() {
    while (gameOver1 == false) {
        system("stty raw");
        input = getchar();
        system("cooked");
    }
}
// Is calld by Game Loop to create the user input thread.
void getDirection() {
    thread th1(getUserInput);
    th1.detach();
    sleep_for(milliseconds(100));
}
void Game::gameLoop() {
    Compass ChangeDirection;
    int index = 0;  // used to keep track of loop iterations
    // Event Loop - runs until game is over
    do {
        index++;
        switch (input) {
            // ADD if up key
            case 'w':
                if (ChangeDirection != SOUTH) {
                    ChangeDirection = NORTH;
                    // for error checking take out later
                    cout << ChangeDirection << endl;
                }
                break;
            // ADD if left key
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
                    // for error checking
                    cout << ChangeDirection << endl;
                }
                break;
            // ADD if right key
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
                    // for error checking
                    cout << ChangeDirection << endl;
                }
                break;
            // ADD if down key
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
                    // for error checking
                    cout << ChangeDirection << endl;
                }
                break;
        }

        // move snake based on direction
        gameSnake.move();

        // check if it hit walls
        if (gameSnake.getPosition().y < 1 || gameSnake.getPosition().y > mapHeight || gameSnake.getPosition().x < 1 ||
            gameSnake.getPosition().x > mapWidth) {
            gameOver = true;
            gameOver1 = true;
            break;
        }

        // lengthen snake if it hits fruit and generate more fruit
        if (gameSnake.getPosition() == gameFruit.getPosition()) {
            gameSnake.lengthen();
            // gameFruit.spawnFruit(mapWidth, mapHeight, board);
        }

        // set cell visited by head position to equal snake length
        if (board[gameSnake.getPosition().y][gameSnake.getPosition().x] > 0) {
            board[gameSnake.getPosition().y][gameSnake.getPosition().x] = gameSnake.getLength();
        } else {
            // snake has hit itself so game is over
            gameOver = true;
            gameOver1 = true;
            break;
        }

        // decrement all of board[][]
        decrementArray();

        cout << index << endl;          // to delete - debugging only
        sleep_for(milliseconds(1000));  // speed of event loop. Higher number is slower

        // should be deleted once proper checking for end of game is added
        if (index == 100) {
            gameOver = true;
            gameOver1 = true;
        }
    } while (!gameOver);
}

void Game::decrementArray() {
    for (int i = 1; i <= mapHeight; ++i) {
        for (int j = 1; j <= mapWidth; ++j) {
            if (board[i][j] > 0) {
                board[i][j] -= 1;
            }
        }
    }
}

void Game::render() {
    ofstream fout;
    fout.open("GameBoard.txt");
    if (!fout) {
        cerr << "cannot open";
    }

    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            Point headPosition;
            headPosition.x = j;
            headPosition.y = i;
            if (board[i][j] == -1) {
                fout << "=  ";
            } else if (board[i][j] == -2) {
                fout << "|  ";
            } else if (board[i][j] > 0 && !(headPosition == gameSnake.getPosition())) {
                fout << "*";
            } else if (headPosition == gameSnake.getPosition()) {
                fout << "O";
            } else {
                fout << board[i][j] << " ";
            }
        }
        fout << endl;
    }

    fout.close();
}

void Game::setGameDifficulty(int choice) {
    if (choice > 3 || choice < 1) {
        throw runtime_error("Choice must be between 1 and 3");
    }
    switch (choice) {
        case 1:
            gameDifficulty = L_EASY;
            break;
        case 2:
            gameDifficulty = L_MEDIUM;
            break;
        case 3:
            gameDifficulty = L_HARD;
            break;
    }
}
