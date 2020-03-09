#include <iostream>
#include <stdexcept>
using namespace std;

void function2(int x) {
    if (x < 0 || x > 3) {
        throw runtime_error("Int not within bounds");
    }
    cout << "got here" << endl;
}

void function1(int x) {
    function2(x);
    cout << "got here 2" << endl;
}

int main() {
    try {
        function1(4);
    } catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
        return 0;
    }
    cout << "Passed test" << endl;

    return 0;
}