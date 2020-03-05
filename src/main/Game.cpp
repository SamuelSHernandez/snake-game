#include "Game.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds

Game::Game(int choice) {
    // set difficulty
    setGameDifficulty(choice);
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
    // initialize board array with zeros
    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            board[i][j] = 0;
        }
    }

    // Position snake
    gameSnake.setLength(2);
    gameSnake.setPosition(mapWidth - 1, mapHeight / 2);
    gameSnake.setAscii('=');
    board[mapHeight / 2][mapWidth] = 1;     // need to set tail in board first time
}

void Game::gameLoop() {
    bool gameOver = false;
    int index = 0;  // used to keep track of loop iterations
    // Event Loop - runs until game is over
    do {
        index++;

        // ADD if up key

        // ADD if left key

        // ADD if right key

        // ADD if down key

        // move snake based on direction
        gameSnake.move();

        // check if it hit walls
        if (gameSnake.getPosition().y < 1 || gameSnake.getPosition().y > mapHeight || gameSnake.getPosition().x < 1 ||
            gameSnake.getPosition().x > mapWidth) {
            gameOver = true;
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
            break;
        }

        // decrement all of board[][]
        decrementArray();

        cout << index << endl;          // to delete - debugging only
        sleep_for(milliseconds(1000));  // speed of event loop. Higher number is slower

        // should be deleted once proper checking for end of game is added
        if (index == 100) {
            gameOver = true;
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
    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            cout << " * ";
        }
    }
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
