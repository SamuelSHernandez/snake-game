#ifndef SRC_MAIN_FRUIT_H_
#define SRC_MAIN_FRUIT_H_
#include "Type.h"

class Game;

class Fruit {
  public:
    Fruit();
    Point getPosition() const;
    void setPosition(const Game &myGame);
    void spawnFruit(const Game &myGame);
    void removeFruit(const Game &myGame);

  private:
    Point position;
};

#endif  // SRC_MAIN_FRUIT_H_