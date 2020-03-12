#ifndef SRC_MAIN_FRUIT_H_
#define SRC_MAIN_FRUIT_H_
#include "Type.h"

class Fruit {
  public:
    Fruit() {
    }
    Point getPosition() const;
    void setPosition(int mapHeight, int mapWidth, Point snakeHead);
void removeFruit(int mapHeight, int mapWidth);
void spawnFruit(int mapHeight, int mapWidth);
  private:
    Point fruitPosition;
};

#endif  // SRC_MAIN_FRUIT_H_