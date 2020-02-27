#ifndef SRC_MAIN_SNAKE_H_
#define SRC_MAIN_SNAKE_H_
#include "Type.h"

class Snake {
  public:
    Snake();
    char move();
    void changeDirection(Compass direction);
    void lengthen();
    void return_head(Point headPosition);

  private:
    int length;
    Compass direction;
    Point headPosition;
};

#endif  // SRC_MAIN_SNAKE_H_