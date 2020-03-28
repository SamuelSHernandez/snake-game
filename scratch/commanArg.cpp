#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    cout << "You have entered " << argc << " arguments" << endl;
    string choice = argv[1];
    cout << "choice: " << choice << endl;
    return 0;
}