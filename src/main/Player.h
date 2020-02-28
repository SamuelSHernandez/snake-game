#ifndef SRC_MAIN_PLAYER_H_
#define SRC_MAIN_PLAYER_H_
#include <string>
#include "Snake.h"  // Player will have a Snake instance
using namespace std;

class Player {
  public:
    Player() {
    }
    string getName() const;
    void setName(string name);
    char getAsciiChar() const;
    void setAsciiChar(char asciiChar);
    int getHighScore() const;
    void setHighScore(int score);

  private:
    string name;
    int score;
    char asciiChar;
    Snake snake;
};

#endif  // SRC_MAIN_PLAYER_H_