#ifndef SRC_MAIN_FRUIT_H_
#define SRC_MAIN_FRUIT_H_

class Fruit {
  private:
    struct Point {
        int fruitX = 0;
        int fruitY = 0;
    };

  public:
    void getPosition(struct Point);
    void setPosition(int fruitX, int fruitY, int mapHeigth, int mapWidth);
    void spawnFruit(int fruitX, int fruitY);
    void removeFruit();
};

#endif  // SRC_MAIN_FRUIT_H_