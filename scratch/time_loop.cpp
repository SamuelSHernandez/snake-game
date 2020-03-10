#include <pthread.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
enum Compass { NORTH, SOUTH, EAST, WEST };

using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds
char direction = 's';
string newDirection;
int stopflag = 0;
char input = 's';
void GetDirection() {
    Compass ChangeDirection;
    while (true && !stopflag) {
        system("stty raw");
        input = getchar();
        switch (input) {
            case 'w':
                if (ChangeDirection != SOUTH) {
                    ChangeDirection = NORTH;
                }
                break;
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
                }
                break;
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
                }
                break;
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
                }
        }
        system("stty cooked");
    }
}
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
