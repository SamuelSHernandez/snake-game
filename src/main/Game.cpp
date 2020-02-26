#include "Game.h"
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds

Game::Game(int x, int y) {
    // initialize board array with space characters
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            board[i][j] = ' ';
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

void render(int mapWidth, int mapHeight, char board, Level gameDifficulty) {
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

    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            cout << " * ";
        }
    }
}
