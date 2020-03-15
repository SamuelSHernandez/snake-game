#include "Game.h"
#include <pthread.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char input = 'a';
bool gameOver1 = false;

Game::Game(int choice, char snakeChar, string playerName) {
    // set difficulty
    setGameDifficulty(choice);
    gameSnake.setAscii(snakeChar);
    // setup initial snake
    gameSnake.setPosition(mapWidth, mapHeight / 2);
    gameSnake.changeDirection(WEST);
    // set player name
    currentPlayer = getPlayer(playerName);

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
// Function to get User Input
void getUserInput() {
    while (gameOver1 == false) {
        input = getchar();
    }
}
// Is calld by Game Loop to create the user input thread.
void getDirection() {
    system("stty raw");
    system("stty echo");
    thread th1(getUserInput);
    th1.detach();
    system("stty -echo");
    system("stty cooked");
}
void Game::gameLoop() {
    Compass ChangeDirection;
    cout << "entered game loop function" << endl;
    bool gameOver = false;
    // set initial fruit
    gameFruit.setPosition(mapHeight, mapWidth, gameSnake.getPosition(), board);

    // Event Loop - runs until game is over
    do {
        index++;
        getDirection();
        switch (input) {
            // if up key
            case 'w':
                if (ChangeDirection != SOUTH) {
                    ChangeDirection = NORTH;
                    gameSnake.changeDirection(NORTH);
                }
                break;
            // if left key
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
                    gameSnake.changeDirection(WEST);
                }
                break;
            // if right key
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
                    gameSnake.changeDirection(EAST);
                }
                break;
            // if down key
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
                    // for error checking
                    gameSnake.changeDirection(SOUTH);
                }
                break;
        }

        // move snake based on direction
        gameSnake.move();
        // board[gameSnake.getPosition().y][gameSnake.getPosition().x] = gameSnake.getLength();

        // check if it hit walls
        if (gameSnake.getPosition().y < 1 || gameSnake.getPosition().y > mapHeight || gameSnake.getPosition().x < 1 ||
            gameSnake.getPosition().x > mapWidth) {
            gameOver = true;
            gameOver1 = true;
            cout << endl << "game over: Hit wall" << endl;
            cout << "Snake Length: " << gameSnake.getLength() << endl;
            addScores();
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
            gameOver1 = true;
            cout << endl << "game over: hit itself" << endl;
            cout << "Snake length: " << gameSnake.getLength() << endl;
            addScores();
            break;
        }

        render();

        // decrement all of board[][]
        decrementArray();

        // cout << "gameLoop iteration: " << index << endl;  // to delete - debugging only
        sleep_for(milliseconds(gameSpeed));  // speed of event loop. Higher number is slower

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

void Game::addScores() {
    currentPlayer->addScore(gameSnake.getLength());
    pair<int, string> tempPair = make_pair(gameSnake.getLength(), currentPlayer->getName());
    switch(gameDifficulty) {
        case L_EASY:
            easyScoresMap.insert(tempPair);
            break;
        case L_MEDIUM:
            mediumScoresMap.insert(tempPair);
            break;
        case L_HARD:
            hardScoresMap.insert(tempPair);
            break;
    }
}

void Game::render() {
    ofstream fout;
    fout.open("Board.txt");
    if (!fout) {
        cerr << "cannot open";
    }
    string space = "  ";
    string fruitSpace;
    if (gameSnake.getLength() < 10) {
        fruitSpace = "  ";
    } else if (gameSnake.getLength() <= 99 && index > 9) {
        fruitSpace = " ";
    } else {
        fruitSpace = "";
    }
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
                fout << to_string(gameSnake.getLength() + 1) + fruitSpace + gridBar;
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
    switch (choice) {
        case 1:
            gameDifficulty = L_EASY;
            gameSpeed = 200;
            break;
        case 2:
            gameDifficulty = L_MEDIUM;
            gameSpeed = 150;
            break;
        case 3:
            gameDifficulty = L_HARD;
            gameSpeed = 100;
            break;
        default:
            cerr << "Invalid input";
            break;
    }
}

Player* Game::getPlayer(string playerName) {
    if (players.count(playerName) == 0) {
        pair<string, Player*> tempPair = make_pair(playerName, new Player(playerName, false));
        players.insert(tempPair);
    }
    return players.at(playerName);
}

void Game::loadStorage() {
    ifstream load;
    string filePlayerName;
    string fileScore;

    // loading players
    load.open("../../storage/playerList.txt");
    if (!load.is_open()) {
        throw runtime_error("Could not open file playerList.txt.");
    }
    getline(load, filePlayerName, '\n');
    while (!load.fail()) {
        pair<string, Player*> tempPair = make_pair(filePlayerName, new Player(filePlayerName, true));
        players.insert(tempPair);
        getline(load, filePlayerName, '\n');
    }
    if (!load.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    load.close();

    // loading easyScoresMap
    load.open("../../storage/EasyLeaderboard.txt");
    if (!load.is_open()) {
        throw runtime_error("Could not open file EasyLeaderboard.txt");
    }
    getline(load, fileScore, '\t');
    getline(load, filePlayerName, '\n');
    while (!load.fail()) {
        pair<int, string> tempPair = make_pair(stoi(fileScore), filePlayerName);
        easyScoresMap.insert(tempPair);
        getline(load, fileScore, '\t');
        getline(load, filePlayerName, '\n');
    }
    if (!load.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    load.close();

    // loading mediumScoresMap
    load.open("../../storage/MediumLeaderboard.txt");
    if (!load.is_open()) {
        throw runtime_error("Could not open file MediumLeaderboard.txt");
    }
    getline(load, fileScore, '\t');
    getline(load, filePlayerName, '\n');
    while (!load.fail()) {
        pair<int, string> tempPair = make_pair(stoi(fileScore), filePlayerName);
        mediumScoresMap.insert(tempPair);
        getline(load, fileScore, '\t');
        getline(load, filePlayerName, '\n');
    }
    if (!load.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    load.close();

    // loading hardScoresMap;
    load.open("../../storage/HardLeaderboard.txt");
    if (!load.is_open()) {
        throw runtime_error("Could not open file HardLeaderboard.txt");
    }
    getline(load, fileScore, '\t');
    getline(load, filePlayerName, '\n');
    while (!load.fail()) {
        pair<int, string> tempPair = make_pair(stoi(fileScore), filePlayerName);
        hardScoresMap.insert(tempPair);
        getline(load, fileScore, '\t');
        getline(load, filePlayerName, '\n');
    }
    if (!load.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    load.close();
}

void Game::printStorage() {
    ofstream save;
    // storing players
    save.open("../../storage/playerList.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file playerList.txt.");
    }
    for (auto each : players) {
        save << each.first << endl;
    }
    save.close();

    // storing easyScoresMap
    save.open("../../storage/EasyLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file EasyLeaderboard.txt.");
    }
    for (auto each : easyScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // storing mediumScoresMap
    save.open("../../storage/MediumLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file MediumLeaderboard.txt.");
    }
    for (auto each : mediumScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // storing hardScoresMap
    save.open("../../storage/HardLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file HardLeaderboard.txt");
    }
    for (auto each : hardScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // store player's scores
    currentPlayer->storeScores();
}
