#ifndef SRC_MAIN_SNAKE_H_
#define SRC_MAIN_SNAKE_H_
#include "Type.h"

class Snake {
  public:
    Snake();
    char move();
    void changeDirection(Compass direction);
    void lengthen();
    Point return_head();

  private:
    int length;
    Compass direction;
    Point headPosition;
};

#endif  // SRC_MAIN_SNAKE_H_