#ifndef SRC_MAIN_SNAKE_H_
#define SRC_MAIN_SNAKE_H_
#include "Type.h"

class Snake {
  public:
    Snake();
    Snake(char ascii, Compass compass, Point position);
    void move();
    void changeDirection(Compass direction) {
        this->direction = direction;
    }
    void lengthen();
    Point return_head() {
        return headPosition;
    }

  private:
    int length;
    char ascii;
    Compass direction;
    Point headPosition;
};

#endif  // SRC_MAIN_SNAKE_H_