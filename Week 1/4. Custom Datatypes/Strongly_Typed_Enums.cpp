#include <iostream>
using namespace std;

enum class Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = Color::GREEN;

    switch (myColor) {
        case Color::RED:
            cout << "Color is Red" << endl;
            break;
        case Color::GREEN:
            cout << "Color is Green" << endl;
            break;
        case Color::BLUE:
            cout << "Color is Blue" << endl;
            break;
    }

    return 0;
}
