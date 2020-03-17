#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    string playerName = "Luke Irvine";
    cout << "Old string: " << playerName << endl;

    try {
        for (int i = 0; i < playerName.length(); ++i) {
            if(65 <= playerName.at(i) && playerName.at(i) <= 90) {
                playerName.at(i) += 32;
            }
            if(playerName.at(i) == 32) {
                playerName.at(i) = 95;
            }
            if(playerName.at(i) == 47) {
                throw runtime_error("Name cannot have '/' character.");
            }
            if(playerName.at(i) == 46) {
                throw runtime_error("name cannot have '.' character.");
            }
        }
    }
    catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "Please run program again." << endl;
        return 0;
    }

    cout << "New string: " << playerName << endl;

    return 0;
}