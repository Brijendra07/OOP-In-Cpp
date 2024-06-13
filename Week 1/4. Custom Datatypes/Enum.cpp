#include <iostream>
using namespace std;

// enum  consists of a set of named integral constants.
enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = GREEN;
    switch (myColor) {
        case RED:
            cout << "Color is Red" << endl;
            break;
        case GREEN:
            cout << "Color is Green" << endl;
            break;
        case BLUE:
            cout << "Color is Blue" << endl;
            break;
    }

    return 0;
}
