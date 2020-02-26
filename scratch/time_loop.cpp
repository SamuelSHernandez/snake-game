#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace this_thread;  // sleep_for, sleep_until
using namespace chrono;       // nanoseconds, system_clock, seconds, milliseconds

int main() {
    char input;
    string direction;
    for (int i = 0; i < 100; ++i) {
        cin >> input;
        switch (input) {
            case 'w':
                direction = "North";
                break;
            case 's':
                direction = "South";
                break;
            case 'a':
                direction = "West";
                break;
            case 'd':
                direction = "East";
        }
        cout << i << endl;
        sleep_for(milliseconds(100));
    }
    return 0;
}