#ifndef SRC_MAIN_GAME_H_
#define SRC_MAIN_GAME_H_
#include "Fruit.h"   // Game will have a Fruit instance
#include "Player.h"  // will have a Player instance
#include "Snake.h"   // will have a Snake instance
#include "Type.h"

class Fruit;
class Snake;
class Player;

class Game {
  public:
    Game(int choice);  // initializes board array of size y by x and sets difficulty. Could throw runtime_error if not
                       // in bounds
    void gameLoop();   // holds game logic and runs the game
    int getMapWidth() const {
        return mapWidth;
    }
    int getMapHeight() const {
        return mapHeight;
    }
    void render();                       // renders the game board
    void setGameDifficulty(int choice);  // accepts int 1, 2, or 3 to set difficulty
                                         // may throw exception if choice is not between 1 and 3
    void decrementArray();               // decreases every value in array by 1

  private:
    int mapWidth;   // variable to hold board width
    int mapHeight;  // variable to hold board height
    Level gameDifficulty;
    Fruit gameFruit;
    Snake gameSnake;
    Player gamePlayer;
    int board[25][25];  // Array size can be changed as necessary. Each difficulty level
                        // only uses as much of the array as needed.
};

#endif  // SRC_MAIN_GAME_H_
