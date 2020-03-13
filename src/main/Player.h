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
    Player(string, char);
 
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
   
    string name;
    int score;
    char asciiChar;
};

#endif  // SRC_MAIN_PLAYER_H_