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

void Player::addScore(int score) {
    scores.push_back(score);
}

void Player::loadScores() {
    ifstream fin;
    string fileNum;  // holds each number from file
    fin.open("../../storage/players/" + name + ".txt");
    if (!fin.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt.");
    }
    // reading numbers
    getline(fin, fileNum, '\n');
    while (!fin.fail()) {
        scores.push_back(stoi(fileNum));
        getline(fin, fileNum, '\n');
    }
    if (!fin.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }
    fin.close();
}

void Player::storeScores() {
    ofstream store;
    // medium scores
    store.open("../../storage/players/" + name + ".txt");
    if (!store.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt");
    }
    for (auto each : scores) {
        store << each << endl;
    }
    store.close();
}
