#ifndef SRC_MAIN_FRUIT_H_
#define SRC_MAIN_FRUIT_H_
#include "Type.h"

class Game;

class Fruit {
  public:
    Fruit();
    Point getPosition() const;
    void setPosition(const Game &myGame);
    void spawnFruit();
    void removeFruit();

  private:
    Point fruitPoint;
};

#endif  // SRC_MAIN_FRUIT_H_