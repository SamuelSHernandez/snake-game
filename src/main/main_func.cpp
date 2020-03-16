#include "main_func.h"
using namespace std;

string getNameEntry() {
    string playerName;
    bool goodString = true;
    do {
        goodString = true;
        cout << "Your name: ";
        getline(cin, playerName, '\n');
        try {
            for (int i = 0; i < playerName.length(); ++i) {
                if (65 <= playerName.at(i) && playerName.at(i) <= 90) {
                    playerName.at(i) += 32;
                }
                if (playerName.at(i) == 32) {
                    playerName.at(i) = 95;
                }
                if (playerName.at(i) == 47) {
                    throw runtime_error("Name cannot have '/' character.");
                }
                if (playerName.at(i) == 46) {
                    throw runtime_error("Name cannot have '.' character.");
                }
            }
        } catch (runtime_error &excpt) {
            cout << excpt.what() << endl;
            goodString = false;
        }
    } while (!goodString);
    return playerName;
}