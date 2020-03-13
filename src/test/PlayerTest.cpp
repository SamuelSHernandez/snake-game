
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    ofstream fout;
    // open file
    fout.open("Leaderboard.txt");

    if (!fout.is_open()) {
        cout << "Could not open file Leaderboard.txt." << endl;
    }

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
    return 0;
}