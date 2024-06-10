#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    // If-Else statement
    if (a > b) {
        std::cout << "a is greater than b" << std::endl;
    } else if (a < b) {
        std::cout << "a is less than b" << std::endl;
    } else {
        std::cout << "a is equal to b" << std::endl;
    }

    // Switch statement
    char c = 'D';
    switch (c) {
        case 'A':
            std::cout << "Character is A" << std::endl;
            break;
        case 'B':
            std::cout << "Character is B" << std::endl;
            break;
        case 'C':
            std::cout << "Character is C" << std::endl;
        default:
            std::cout << "Character is not A, B or C" << std::endl;
            break;
    }

    // For loop
    for (int i = 0; i < 5; i++) {
        std::cout << "For loop iteration: " << i << std::endl;
    }

    // While loop
    int j = 0;
    while (j < 5) {
        std::cout << "While loop iteration: " << j << std::endl;
        j++;
    }

    // Do-While loop
    int k = 0;
    do {
        std::cout << "Do-While loop iteration: " << k << std::endl;
        k++;
    } while (k < 5);

    return 0;
}
