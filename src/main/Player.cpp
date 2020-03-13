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
    ofstream fout;
    fout.open("Leaderboard.txt");

    if (!fout.is_open()) {
        cout << "Could not open file Leaderboard.txt." << endl;
    }

    // open file

    fout << "***********************************************" << endl;
    fout << setw(28) << "LEADERBOARD" << setw(32) << endl;
    fout << "      --------------------------------   " << endl;
    fout << setw(12) << "Player " << setw(16) << " Difficulty " << setw(16) << " High Score " << endl;
    fout << "      --------------------------------   " << endl;

    fout << "\t " << endl;
    // fout current player
    // fout current highscore
    // compare with current highscores and replace if higher
    fout << "***********************************************" << endl;

    // close file

    fout.close();
}
