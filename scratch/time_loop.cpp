#include <pthread.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
<<<<<<< HEAD
enum Compass { NORTH, SOUTH, EAST, WEST };

=======
class Game {
  public:
    void Runstuff();
};
enum Compass { NORTH, SOUTH, EAST, WEST };
Compass ChangeDirection;
>>>>>>> master
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char direction = 's';
<<<<<<< HEAD
string newDirection;
int stopflag = 0;
char input = 's';
void GetDirection() {
    Compass ChangeDirection;
    while (true && !stopflag) {
        system("stty raw");
        input = getchar();
=======
int stopflag = 0;
char input = 's';
void GetDirection() {

    while (true && !stopflag) {
        system("stty raw");
        input = getchar();
        
>>>>>>> master
        switch (input) {
            case 'w':
                if (ChangeDirection != SOUTH) {
                    ChangeDirection = NORTH;
<<<<<<< HEAD
=======
                    cout << ChangeDirection << endl;
>>>>>>> master
                }
                break;
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
<<<<<<< HEAD
=======
                    cout << ChangeDirection << endl;
>>>>>>> master
                }
                break;
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
<<<<<<< HEAD
=======
                    cout << ChangeDirection << endl;
>>>>>>> master
                }
                break;
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
<<<<<<< HEAD
=======
                    cout << ChangeDirection << endl;
>>>>>>> master
                }
        }
        system("stty cooked");
    }
}
<<<<<<< HEAD
void MoveSnake() {
    this_thread::sleep_for(10s);
    cout << input << endl;
}
void CheckSnake() {
    thread th1(GetDirection);
    thread th2(MoveSnake);
    if (input == 'p') {
        stopflag = 1;
    }
    th1.detach();
    th2.detach();
}
int main() {
    char input;
    string direction;
    do {
        CheckSnake();
        cout << input << endl;

    } while (stopflag == 0);
    //    th2.join();
    //    cout<<"Move Snake has joined"<<endl;
    cout << endl << direction << endl;
    return 0;
}
=======

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
>>>>>>> master
