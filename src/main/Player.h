#ifndef SRC_MAIN_PLAYER_H_
#define SRC_MAIN_PLAYER_H_
#include <string>
#include "Snake.h"  // Player will have a Snake instance
using namespace std;

class Player {
  public:
    Player();
    Player(string, char);
    string getName() const {
        return name;
    };
    void setName(string name) {
        this->name = name;
    };
    char getAsciiChar() const {
        return asciiChar;
    };
    void setAsciiChar(char asciiChar) {
        this->asciiChar = asciiChar;
    };
    int getHighScore() const {
        return score;
    };
    void setHighScore(int score) {
        this->score = score;
    };

  private:
    string name;
    int score;
    char asciiChar;
};

#endif  // SRC_MAIN_PLAYER_H_