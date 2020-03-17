#include "Game.h"
#include <pthread.h>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char input = 'a';
bool gameOver1 = false;

Game::Game(int choice, char snakeChar, string playerName) : gameOver(false), mapWidth(20), mapHeight(20), index(0) {
    // set difficulty
    setGameDifficulty(choice);
    gameSnake.setAscii(snakeChar);
    // setup initial snake
    gameSnake.setPosition(mapWidth, mapHeight / 2);
    gameSnake.changeDirection(WEST);
    // set player name
    this->playerName = playerName;

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

    render();
}
// Function to get User Input
void getUserInput() {
    while (gameOver1 == false) {
        // different way of doing cin
        input = getchar();
    }
}
// Is called by Game Loop to create the user input thread.
void getDirection() {
    // raw makes it so it doesn't have to have the enter
    system("stty raw");
    // echo makes it so it doesn't print the input in the terminal
    system("stty echo");
    // calls the thread
    thread th1(getUserInput);
    // detachs the thread so it doesn't have to wait for the input if there isn't any
    th1.detach();
    // turning off the stuff
    system("stty -echo");
    system("stty cooked");
}
void Game::gameLoop() {
    Compass direction;
    bool gameOver = false;

    // set initial fruit
    gameFruit.setPosition(mapHeight, mapWidth, gameSnake.getPosition(), board);

    // Event Loop - runs until game is over
    do {
        index++;
        if (index == 1) {
            direction = WEST;
            gameSnake.changeDirection(WEST);
        }
        getDirection();
        switch (input) {
            // if up key
            case 'w':
                if (direction != SOUTH) {
                    direction = NORTH;
                    gameSnake.changeDirection(NORTH);
                }
                break;
            // if left key
            case 'a':
                if (direction != EAST) {
                    direction = WEST;
                    gameSnake.changeDirection(WEST);
                }
                break;
            // if right key
            case 'd':
                if (direction != WEST) {
                    direction = EAST;
                    gameSnake.changeDirection(EAST);
                }
                break;
            // if down key
            case 's':
                if (direction != NORTH) {
                    direction = SOUTH;
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
            cout << endl << endl << "Game Over: Hit wall" << endl;
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
            cout << endl << endl << "Game Over: hit itself" << endl;
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
    currentPlayer->addScore(gameSnake.getLength(), gameDifficulty);
    pair<int, string> tempPair = make_pair(gameSnake.getLength(), currentPlayer->getName());
    switch (gameDifficulty) {
        case L_EASY:
            easyScoresMap.push_back(tempPair);
            break;
        case L_MEDIUM:
            mediumScoresMap.push_back(tempPair);
            break;
        case L_HARD:
            hardScoresMap.push_back(tempPair);
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
    if (gameSnake.getLength() <= 8) {
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

    // // debugging
    // fout << endl << endl << endl;
    // for (int i = 0; i < mapHeight + 2; i++) {
    //     for (int j = 0; j < mapWidth + 2; j++) {
    //         fout << board[i][j];
    //     }
    //     fout << endl;
    // }

    fout.close();
}

void Game::setGameDifficulty(int choice) {  // sets the game's difficulty
    switch (choice) {
        case 1:
            gameDifficulty = L_EASY;
            gameSpeed = 160;
            break;
        case 2:
            gameDifficulty = L_MEDIUM;
            gameSpeed = 130;
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

Player* Game::getPlayer(string playerName) {  // saves new players
    if (players.count(playerName) == 0) {
        pair<string, Player*> tempPair = make_pair(playerName, new Player(playerName, false));
        players.insert(tempPair);
    }
    return players.at(playerName);
}

void Game::loadStorage() {  // Holds the player's information for leaderboard retrieval
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

    // load current player object into currentPlayer
    currentPlayer = getPlayer(playerName);

    // loading easyScoresMap
    load.open("../../storage/EasyLeaderboard.txt");
    if (!load.is_open()) {
        throw runtime_error("Could not open file EasyLeaderboard.txt");
    }
    getline(load, fileScore, '\t');
    getline(load, filePlayerName, '\n');
    while (!load.fail()) {
        pair<int, string> tempPair = make_pair(stoi(fileScore), filePlayerName);
        easyScoresMap.push_back(tempPair);
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
        mediumScoresMap.push_back(tempPair);
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
        hardScoresMap.push_back(tempPair);
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
    for (const auto each : players) {
        save << each.first << endl;
    }
    save.close();

    // storing easyScoresMap
    save.open("../../storage/EasyLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file EasyLeaderboard.txt.");
    }
    for (const auto each : easyScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // storing mediumScoresMap
    save.open("../../storage/MediumLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file MediumLeaderboard.txt.");
    }
    for (const auto each : mediumScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // storing hardScoresMap
    save.open("../../storage/HardLeaderboard.txt");
    if (!save.is_open()) {
        throw runtime_error("Could not open file HardLeaderboard.txt");
    }
    for (const auto each : hardScoresMap) {
        save << each.first << "\t" << each.second << endl;
    }
    save.close();

    // store player's scores
    currentPlayer->storeScores();
}

void Game::printLeaderboard() {  // Prints the leaderboard based on difficulty level
    switch (gameDifficulty) {
        case L_EASY:
            easyScoresMap.sort(greater<pair<int, string> >());
            printEasyHeader();
            break;
        case L_MEDIUM:
            mediumScoresMap.sort(greater<pair<int, string> >());
            printMediumHeader();
            break;
        case L_HARD:
            hardScoresMap.sort(greater<pair<int, string> >());
            printHardHeader();
            break;
    }
    // calculate highest player score
    int playerHighest = 0;
    for (const auto each : currentPlayer->getScores()) {
        if (each.first > playerHighest && each.second == gameDifficulty) {
            playerHighest = each.first;
        }
    }
    cout << "Your latest score: " << gameSnake.getLength() << endl;   // Gives player's latest score
    cout << "Your highest score: " << playerHighest << endl << endl;  // Gives player's highest score
}

void Game::printEasyHeader() {  // prints leaderboard for Level: Easy
    cout << "============================================================================" << endl;
    cout << "|                          H I G H   S C O R E S                           |" << endl;
    cout << "|                              Level: Easy                                 |" << endl;
    cout << "============================================================================" << endl;
    list<pair<int, string> >::iterator i;
    int count = 1;
    for (i = easyScoresMap.begin(); i != easyScoresMap.end() && count != 11; ++i) {
        cout << "                            ";
        cout << count << ":\t" << formatName(i->second) << "\t" << i->first << endl;
        count++;
    }
}

void Game::printMediumHeader() {  // prints leaderboard for Level: Medium
    cout << "============================================================================" << endl;
    cout << "|                          H I G H   S C O R E S                           |" << endl;
    cout << "|                             Level: Medium                                |" << endl;
    cout << "============================================================================" << endl;
    list<pair<int, string> >::iterator i;
    int count = 1;
    for (i = mediumScoresMap.begin(); i != mediumScoresMap.end() && count != 11; ++i) {
        cout << "                            ";
        cout << count << ":\t" << formatName(i->second) << "\t" << i->first << endl;
        count++;
    }
}

void Game::printHardHeader() {  // prints leaderboard for Level: Hard
    cout << "============================================================================" << endl;
    cout << "|                          H I G H   S C O R E S                           |" << endl;
    cout << "|                              Level: Hard                                 |" << endl;
    cout << "============================================================================" << endl;
    list<pair<int, string> >::iterator i;
    int count = 1;
    for (i = hardScoresMap.begin(); i != hardScoresMap.end() && count != 11; ++i) {
        cout << "                            ";
        cout << count << ":\t" << formatName(i->second) << "\t" << i->first << endl;
        count++;
    }
}

string Game::formatName(string name) {  // formats player's name
    for (int i = 0; i < name.length(); ++i) {
        if (name.at(i) == 95) {
            name.at(i) = 32;
        }
        if (i == 0 || name.at(i - 1) == 32) {
            // capitalize if first letter or first letter after space
            name.at(i) -= 32;
        }
    }
    return name;
}
