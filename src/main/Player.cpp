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

Player::Player(string name, bool old) {
    this->name = name;
    if (old) {
        loadScores();
    }
}

void Player::addScore(int score) {
    cout << "player scores just before pushing back: " << endl;
    for (auto each : scores) {
        cout << each << ", ";
    }
    cout << endl;
    scores.push_back(score);
    cout << "new player scores vector after saving: " << endl;
    for (auto each : scores) {
        cout << each << ", ";
    }
    cout << endl;
}

void Player::loadScores() {
    ifstream fin;
    string fileNum;  // holds each number from file
    fin.open("../../storage/players/" + name + ".txt");
    if (!fin.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt.");
    }
    cout << "Openning player file: " << endl;
    cout << "../../storage/players/" + name + ".txt" << endl;
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

    cout << name + " scores vector: " << endl;
    for (auto each : scores) {
        cout << each << ", ";
    }
    cout << endl;
}

void Player::storeScores() {
    ofstream store;
    // medium scores
    cout << "Name: " << name << endl;
    cout << "Name of file being saved: " << endl << name + ".txt" << endl;
    store.open("../../storage/players/" + name + ".txt");
    if (!store.is_open()) {
        throw runtime_error("Could not open file " + name + ".txt");
    }
    for (auto each : scores) {
        store << each << endl;
    }
    cout << "Scores being saved to file from " << name << ": " << endl;
    for (auto each : scores) {
        cout << each << ", ";
    }
    cout << endl;

    store.close();
}
