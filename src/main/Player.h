#ifndef SRC_MAIN_PLAYER_H_
#define SRC_MAIN_PLAYER_H_
#include <string>
#include "Snake.h"  // Player will have a Snake instance
using namespace std;

class Snake;

class Player {
  public:
    Player(string);
    string getName() const {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    int getHighScore() const {
        return score;
    }
    void setHighScore(int score) {
        this->score = score;
    }

  private:
    string name;
    int score;
};

#endif  // SRC_MAIN_PLAYER_H_