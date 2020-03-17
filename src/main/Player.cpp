#include "Player.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

Player::Player() {
    name = "NULL";
}

Player::Player(string name, bool old) {
    this->name = name;
    if (old) {
        loadScores();
    }
}

// Adds a player's score and the associated game difficulty
void Player::addScore(int score, Level difficulty) {
    pair<int, Level> tempPair = make_pair(score, difficulty);
    scores.push_back(tempPair);
}

// Opens a new file based on player name
void Player::loadScores() {
    ifstream fin;
    string fileNum;         // holds each number from file
    string fileDifficulty;  // holds difficulty level from file
    pair<int, Level> tempPair;

    fin.open("../../storage/players/" + name + ".txt");
    if (!fin.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt.");
    }
    // reading numbers
    getline(fin, fileNum, '\t');
    getline(fin, fileDifficulty, '\n');
    while (!fin.fail()) {
        switch (stoi(fileDifficulty)) {
            case 0:
                tempPair = make_pair(stoi(fileNum), L_EASY);
                break;
            case 1:
                tempPair = make_pair(stoi(fileNum), L_MEDIUM);
                break;
            case 2:
                tempPair = make_pair(stoi(fileNum), L_HARD);
                break;
        }
        scores.push_back(tempPair);
        getline(fin, fileNum, '\t');
        getline(fin, fileDifficulty, '\n');
    }
    if (!fin.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    fin.close();
}

// Stores score in the appropriate player file
void Player::storeScores() {
    ofstream store;
    // medium scores
    store.open("../../storage/players/" + name + ".txt");
    if (!store.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt");
    }
    for (const auto each : scores) {
        store << each.first << '\t' << each.second << endl;
    }
    store.close();
}
