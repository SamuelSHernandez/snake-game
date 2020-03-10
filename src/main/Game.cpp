#include "Game.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds

Game::Game(int choice) : gameSnake('*') {
    // set difficulty
    setGameDifficulty(choice);
    // set map size based on gameDifficulty member variable
    switch (gameDifficulty) {
        case L_EASY:
            mapWidth = 20;
            mapHeight = 20;

            break;

        case L_MEDIUM:
            mapWidth = 40;
            mapHeight = 40;

            break;

        case L_HARD:
            mapWidth = 60;
            mapHeight = 60;

            break;
    }

    // setup initial snake
    gameSnake.setPosition(mapWidth, mapHeight / 2);
    gameSnake.changeDirection(WEST);

    // sets the array with blank spaces with game difficulty size and negative numbers for borders
    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            if (i == 0 || i == mapHeight + 1) {
                board[i][j] = -1;
            } else if (j == 0 || j == mapWidth + 1) {
                board[i][j] = -2;
            } else if (gameSnake.getPosition().x == j && gameSnake.getPosition().y == i) {
                // set array position where snake head is at to 1 initially (trust me)
                // we don't need to initialize tail position yet
                board[i][j] = 1;
            } else {
                // set all spaces with nothing happening to 0
                board[i][j] = 0;
            }
        }
    }

    // // Position snake
    // gameSnake.setLength(2);
    // gameSnake.setPosition(mapWidth - 1, mapHeight / 2);
    // gameSnake.setAscii('=');
    // board[mapHeight / 2][mapWidth] = 1;  // need to set tail in board first time
}

void Game::gameLoop() {
    cout << "entered game loop function" << endl;
    bool gameOver = false;
    int index = 0;  // used to keep track of loop iterations

    // set initial fruit
    gameFruit.setPosition(mapHeight, mapWidth, gameSnake.getPosition(), board);

    // Event Loop - runs until game is over
    do {
        index++;

        // testing change direction (automated)
        switch (index) {
            case 15:
                gameSnake.changeDirection(SOUTH);
                break;
            case 24:
                gameSnake.changeDirection(EAST);
                break;
            case 36:
                gameSnake.changeDirection(NORTH);
                break;
            case 42:
                gameSnake.changeDirection(WEST);
                break;
            case 55:
                gameSnake.changeDirection(SOUTH);
                break;
            case 61:
                gameSnake.changeDirection(WEST);
                break;
            case 62:
                gameSnake.changeDirection(NORTH);
                break;
            case 75:
                gameSnake.changeDirection(EAST);
                break;
            case 76:
                gameSnake.changeDirection(SOUTH);
                break;
            case 77:
                gameSnake.changeDirection(WEST);
                break;
        }

        // ADD if up key

        // ADD if left key

        // ADD if right key

        // ADD if down key

        // move snake based on direction
        gameSnake.move();
        // board[gameSnake.getPosition().y][gameSnake.getPosition().x] = gameSnake.getLength();

        // check if it hit walls
        if (gameSnake.getPosition().y < 1 || gameSnake.getPosition().y > mapHeight || gameSnake.getPosition().x < 1 ||
            gameSnake.getPosition().x > mapWidth) {
            gameOver = true;
            cout << "game over: Hit wall" << endl;
            cout << "Snake Length: " << gameSnake.getLength() << endl;
            break;
        }

        // lengthen snake if it hits fruit and generate more fruit
        if (gameSnake.getPosition() == gameFruit.getPosition()) {
            gameSnake.lengthen();
            gameFruit.setPosition(mapWidth, mapHeight, gameSnake.getPosition(), board);
        }

        // set cell visited by head position, set cell to equal snake length
        if (board[gameSnake.getPosition().y][gameSnake.getPosition().x] == 0 ||
            board[gameSnake.getPosition().y][gameSnake.getPosition().x] == -3) {
            board[gameSnake.getPosition().y][gameSnake.getPosition().x] = gameSnake.getLength();
        } else {
            // snake has hit itself so game is over
            gameOver = true;
            cout << "game over: hit itself" << endl;
            cout << "Snake length: " << gameSnake.getLength() << endl;
            break;
        }

        render();

        // decrement all of board[][]
        decrementArray();

        cout << "gameLoop iteration: " << index << endl;  // to delete - debugging only
        sleep_for(milliseconds(150));                     // speed of event loop. Higher number is slower

        // should be deleted once proper checking for end of game is added
        if (index == 100) {
            gameOver = true;
        }
    } while (!gameOver);
    // handle end of game
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
    string space = "  ";
    string gridBar = "";
    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            Point arrayPosition;
            arrayPosition.x = j;
            arrayPosition.y = i;
            if (board[i][j] == -1) {
                fout << "=" + space + gridBar;
            } else if (board[i][j] == -2) {
                fout << "|" + space;
            } else if (board[i][j] > 0 && !(arrayPosition == gameSnake.getPosition())) {
                fout << gameSnake.getAscii() + space + gridBar;
            } else if (arrayPosition == gameSnake.getPosition()) {
                fout << "O" + space + gridBar;
            } else if (board[i][j] == -3) {
                fout << "8" + space + gridBar;
            } else {
                fout << " " + space + gridBar;
            }
        }
        fout << endl;
    }

    // debugging
    fout << endl << endl << endl;
    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            fout << board[i][j];
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
