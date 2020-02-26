#ifndef SRC_MAIN_GAME_H_
#define SRC_MAIN_GAME_H_
#include "Fruit.h"   // Game will have a Fruit instance
#include "Player.h"  // will have a Player instance
#include "Snake.h"   // will have a Snake instance

enum Level { L_EASY, L_MEDIUM, L_HARD };

class Game {
  public:
    Game(int x, int y);  // initializes board array of size y by x
    void render();       // renders the game board
    void gameLoop();     // holds game logic and runs the game

  private:
    int mapWidth = 0;   // variable to hold board width
    int mapHeight = 0;  // variable to hold board height
    Level gameDifficulty;
    Fruit gameFruit;
    Snake gameSnake;
    Player gamePlayer;
    char board[20][20];  // Array size can be changed as necessary. Each difficulty level
                         // only uses as much of the array as needed.
};

#endif  // SRC_MAIN_GAME_H_