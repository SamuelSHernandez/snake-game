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

Player::Player(string myName) {
    myName = name;
}

// make vector of pointers with name (pointers that point to score)
// emplace vector and difficutly

void printLeaderboard() {
    ofstream outFS;
    // open file
    outFS.open("Leaderboard.txt");

    outFS.open("Leaderboard.txt");
    if (!outFS.is_open()) {
        cout << "Could not open file Leaderboard.txt." << endl;
    }

    outFS << "***********************************************";
    outFS << setw(6) << "Player "
          << " Difficulty "
          << " High Score " << endl;

    outFS << "\t test runs well";
    // fout current player
    // fout current highscore
    // compare with current highscores and replace if higher
    outFS << "***********************************************";

    // close file

    outFS.close();
}
