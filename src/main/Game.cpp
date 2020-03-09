#include "Game.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <pthread.h>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char input='s';
bool gameOver=false;
Compass ChangeDirection;
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
    board[mapHeight / 2][mapWidth] = 1;  // need to set tail in board first time
}
//Function to get User Input
void getUserInput(){
    while(gameOver==false){
system("stty raw");
input =getchar();
switch(input){
        // ADD if up key
        case 'w':
        if(ChangeDirection!=SOUTH){
            ChangeDirection=NORTH;
            //for error checking take out later
            cout<<ChangeDirection<<endl;
        }
        break;
        // ADD if left key
        case 'a':
        if(ChangeDirection!=EAST){
            ChangeDirection=WEST;
            //for error checking
            cout<<ChangeDirection<<endl;
        }
        break;
        // ADD if right key
        case 'd':
        if(ChangeDirection!=WEST){
            ChangeDirection=EAST;
            //for error checking 
            cout<<ChangeDirection<<endl;
        }
        break;
        // ADD if down key
        case 's':
        if(ChangeDirection!=NORTH){
            ChangeDirection=SOUTH;
            //for error checking 
            cout<<ChangeDirection<<endl;
        }
        break;
        default:
        //not really sure what to put in here.
        cout<<ChangeDirection<<endl;
        break;
        }
system("cooked");
    }
}
//Is calld by Game Loop to create the user input thread.
void getDirection(){
   
    thread th1(getUserInput);
    th1.detach();
}
void Game::gameLoop() {
    enum Compass { NORTH, SOUTH, EAST, WEST };
    Compass ChangeDirection;
    int index = 0;  // used to keep track of loop iterations
    // Event Loop - runs until game is over
    do {
        index++;
        getDirection();
        
        // ADD if snake hits itself or wall

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
