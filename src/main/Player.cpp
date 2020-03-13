#include "Player.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
Player::Player() {
    name = "NULL";
    score = 0;
    asciiChar = '.';
}

Player::Player(string myName, char asciiChar) {
    myName = name;
}

// make vector of pointers with name (pointers that point to score)
// emplace vector and difficutly

void printLeaderboard() {
    // easy
    ofstream Easyfout;
    Easyfout.open("EasyLeaderboard.txt");

    if (!Easyfout.is_open()) {
        cout << "Could not open file EasyLeaderboard.txt." << endl;
    }

    for (const auto& [k, v] : easyScoresMap) {
        cout << k << "\t" << v;
    }

    Easyfout.close();

    // medium
    ofstream Mediumfout;
    Easyfout.open("MediumLeaderboard.txt");

    if (!Mediumfout.is_open()) {
        cout << "Could not open file MediumLeaderboard.txt." << endl;
    }

    for (const auto& [k, v] : mediumScoresMap) {
        cout << k << "\t" << v;
    }
    Mediumfout.close();

    // hard
    ofstream Hardfout;
    Hardfout.open("MediumLeaderboard.txt");

    if (!Hardfout.is_open()) {
        cout << "Could not open file MediumLeaderboard.txt." << endl;
    }
    for (const auto& [k, v] : hardScoresMap) {
        cout << k << "\t" << v;
    }

    Hardfout.close();
}
