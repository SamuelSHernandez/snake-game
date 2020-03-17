#ifndef SRC_MAIN_PLAYER_H_
#define SRC_MAIN_PLAYER_H_
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "Snake.h"  // Player will have a Snake instance
using namespace std;

class Snake;

class Player {
  public:
    Player();
    Player(string, bool);  // name of player, flag saying if player exists in storage
    string getName() const {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    vector<pair<int, Level> > getScores() const {
        return scores;
    }
    void addScore(int score, Level difficulty);
    void loadScores();   // can throw exception
    void storeScores();  // can throw exception

    void printLeaderboard();

  private:
    string name;
    vector<pair<int, Level> > scores;
};

#endif  // SRC_MAIN_PLAYER_H_