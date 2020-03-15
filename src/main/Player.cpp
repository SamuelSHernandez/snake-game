#include "Player.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
Player::Player() {
    name = "NULL";
}

Player::Player(string myName, bool old) {
    this->name = name;
    if (old) {
        loadScores();
    }
}

void Player::loadScores() {
    ifstream fin;
    int fileNum;  // holds each number from file
    // open file
    fin.open("../../storage/players/" + name + ".txt");

    if (!fin.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt.");
    }

    // reading numbers
    fin >> fileNum;
    while (!fin.fail()) {
        scores.push_back(fileNum);
        fin >> fileNum;
    }
    if (!fin.eof()) {
        throw runtime_error("Input failure before reaching end of file.");
    }

    fin.close();
}

void Player::storeScores(int newScore) {
    ofstream store;
    // medium scores
    store.open("../../storage/players/" + name + ".txt");
    if (!store.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt");
    }

    for (auto each : scores) {
        store << each << endl;
    }
    store << newScore << endl;

    store.close();
}
