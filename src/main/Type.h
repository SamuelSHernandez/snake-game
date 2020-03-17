#ifndef SRC_MAIN_TYPE_H_
#define SRC_MAIN_TYPE_H_

enum Compass { NORTH, SOUTH, EAST, WEST };  // movement direction

struct Point {  // Snake head position
    int x;
    int y;
};

bool operator==(Point lhs, Point rhs);

enum Level { L_EASY, L_MEDIUM, L_HARD };  // Game difficulty

#endif  // SRC_MAIN_TYPE_H_
