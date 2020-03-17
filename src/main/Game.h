#ifndef SRC_MAIN_GAME_H_
#define SRC_MAIN_GAME_H_
#include <pthread.h>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "Fruit.h"   // Game will have a Fruit instance
#include "Player.h"  // will have a Player instance
#include "Snake.h"   // will have a Snake instance
#include "Type.h"

class Fruit;
class Snake;
class Player;

class Game {
  public:
    Game(int choice, char snakeChar, string playerName);  // initializes board array of size y by x and sets difficulty.
                                                          // Could throw runtime_error if not in bounds
    void gameLoop();                                      // holds game logic and runs the game
    int getMapWidth() const {
        return mapWidth;
    }
    int getMapHeight() const {
        return mapHeight;
    }
    void render();                       // renders the game board
    void setGameDifficulty(int choice);  // accepts int 1, 2, or 3 to set difficulty
                                         // may throw exception if choice is not between 1 and 3
    Level getGameDifficulty() const {
        return gameDifficulty;
    }
    void decrementArray();  // decreases every value in array by 1
    map<string, Player*> getPlayers() const {
        return players;
    }
    list<pair<int, string> > getEasyScoresMap() const {
        return easyScoresMap;
    }
    list<pair<int, string> > getMediumScoresMap() const {
        return mediumScoresMap;
    }
    list<pair<int, string> > getHardScoresMap() const {
        return hardScoresMap;
    }
    Player* getPlayer(string);
    void addScores();
    void loadStorage();   // can throw exception
    void printStorage();  // can throw exception
    void printLeaderboard();
    void printEasyHeader();
    void printMediumHeader();
    void printHardHeader();
    string formatName(string);

    void printLeaderboard(map<int, string>, map<int, string>, map<int, string>);

  private:
    bool gameOver;
    int mapWidth;   // variable to hold board width
    int mapHeight;  // variable to hold board height
    int index;      // used to keep track of loop iterations
    string playerName;
    Player* currentPlayer;
    Level gameDifficulty;
    Fruit gameFruit;
    Snake gameSnake;
    int board[100][100];                     // Array size can be changed as necessary. Each difficulty level
                                             // only uses as much of the array as needed.
    int gameSpeed;                           // number of milliseconds snake will sleep between iterations
    map<string, Player*> players;            // <name, player object>
    list<pair<int, string> > easyScoresMap;  // <score, player name>
    list<pair<int, string> > mediumScoresMap;
    list<pair<int, string> > hardScoresMap;
};

#endif  // SRC_MAIN_GAME_H_
