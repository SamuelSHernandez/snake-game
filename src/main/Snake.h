#ifndef SRC_MAIN_SNAKE_H_
#define SRC_MAIN_SNAKE_H_
#include "Type.h"

class Snake {
  public:
    Snake();
    void move();  // used to move snake
    void changeDirection(Compass direction) {
        this->direction = direction;
    }
    void lengthen();  // increases the length of snake
    int getLength() const {
        return length;
    }
    void setLength(int l) {
        length = l;
    }
    Point getPosition() {
        return headPosition;
    }
    void setPosition(int x, int y) {
        headPosition.x = x;
        headPosition.y = y;
    }
    void setAscii(char ascii);
    char getAscii() const {
        return ascii;
    }

  private:
    int length;
    char ascii;
    Compass direction;
    Point headPosition;
};

#endif  // SRC_MAIN_SNAKE_H_