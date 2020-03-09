#include "Game.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds

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
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            if (i == 0 || i == mapHeight + 1) {
                board[i][j] = '=';
            } else if (j == 0 || j == mapWidth + 1) {
                board[i][j] = '|';
            }
        }
    }
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

        // ADD if snake hits itself or wall

        cout << index << endl;         // to delete - debugging only
        sleep_for(milliseconds(300));  // speed of event loop. Higher number is slower
        // should be deleted once proper checking for end of game is added
        if (index == 100) {
            gameOver = true;
        }
    } while (!gameOver);
}

void Game::render() {
    ofstream fout;
    fout.open("GameBoard.txt");
    if (!fout) {
        cerr << "cannot open";
    }

    for (int i = 0; i < mapHeight + 2; i++) {
        for (int j = 0; j < mapWidth + 2; j++) {
            fout << board[i][j] << " ";
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
