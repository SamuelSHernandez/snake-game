#include <pthread.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
class Game {
  public:
    void Runstuff();
};
enum Compass { NORTH, SOUTH, EAST, WEST };
Compass ChangeDirection;
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char direction = 's';
int stopflag = 0;
char input = 's';
void GetDirection() {

    while (true && !stopflag) {
        system("stty raw");
        input = getchar();
        
        switch (input) {
            case 'w':
                if (ChangeDirection != SOUTH) {
                    ChangeDirection = NORTH;
                    cout << ChangeDirection << endl;
                }
                break;
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
                    cout << ChangeDirection << endl;
                }
                break;
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
                    cout << ChangeDirection << endl;
                }
                break;
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
                    cout << ChangeDirection << endl;
                }
        }
        system("stty cooked");
    }
}

void CheckSnake() {
    thread th1(GetDirection);
    th1.detach();
    if (input == 'p') {
        stopflag = 1;
    }
}

int main() {
    char input;
    string direction;
    Compass ChangeDirection;
    do {
         Game Game;
         Game.Runstuff();
          
        cout<<input<<endl;
    } while (stopflag == 0);
    //    th2.join();
    //    cout<<"Move Snake has joined"<<endl;
    return 0;
}

void Game::Runstuff() {
    CheckSnake();
        Compass ChangeDirection;
   
}
