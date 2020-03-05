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
                    cout<<ChangeDirection<<endl;
                }
                break;
            case 'a':
                if (ChangeDirection != EAST) {
                    ChangeDirection = WEST;
                    cout<<ChangeDirection<<endl;
                }
                break;
            case 's':
                if (ChangeDirection != NORTH) {
                    ChangeDirection = SOUTH;
                    cout<<ChangeDirection<<endl;
                }
                break;
            case 'd':
                if (ChangeDirection != WEST) {
                    ChangeDirection = EAST;
                    cout<<ChangeDirection<<endl;
                }
        }
        system("stty cooked");
    }
}

void CheckSnake() {
    thread th1(GetDirection);
    if (input == 'p') {
        stopflag = 1;
    }
    th1.detach();
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
