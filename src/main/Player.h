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
    Player(string, bool);       // name of player, flag saying if player exists in storage
    string getName() const {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    vector<int> getScores() const {
        return scores;
    }
    void setHighScore(int score) {
        scores.push_back(score);
    }
    void loadScores();  // can throw exception
    void storeScores(int); // can throw exception

  private:
    string name;
    vector<int> scores;
};

#endif  // SRC_MAIN_PLAYER_H_