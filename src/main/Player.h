#ifndef SRC_MAIN_PLAYER_H_
#define SRC_MAIN_PLAYER_H_
#include <map>
#include <string>
#include <vector>
#include "Snake.h"  // Player will have a Snake instance
using namespace std;

class Snake;

class Player {
  public:
    Player();
    Player(string);
    vector<Player *> getName() const {
        return player;
    }
    void setName(string name) {
        this->name = name;
    }
    char getAsciiChar() const {
        return asciiChar;
    }
    void setAsciiChar(char asciiChar) {
        this->asciiChar = asciiChar;
    }
    int getHighScore() const {
        return score;
    }
    void setHighScore(int score) {
        this->score = score;
    }

    void printLeaderboard();

  private:
    vector<Player *> player;                     // holds pointers to
    map<vector<Player *> *, int> highscore;      // holds name as a key to a highscore
    map<vector<Player *> *, string> difficulty;  // holds name as a key to a difficulty
    string name;
    int score;
    char asciiChar;
};

#endif  // SRC_MAIN_PLAYER_H_