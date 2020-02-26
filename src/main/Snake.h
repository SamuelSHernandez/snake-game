#ifndef SRC_MAIN_SNAKE_H_
#define SRC_MAIN_SNAKE_H_

enum Compass { NORTH, SOUTH, EAST, WEST };

struct Point {
    int dx;
    int dy;
};

class Snake {
  private:
    int length;
    Compass direction;
    Point headPosition;

  public:
    Snake();
    char move();
    void changeDirection(Compass direction);
    void lengthen();
    void return_head(Point headPosition);
};

#endif  // SRC_MAIN_SNAKE_H_