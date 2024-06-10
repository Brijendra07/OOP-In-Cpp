#include <iostream>

// Function declaration
int add(int x, int y);

// Function with parameter passing by reference
void swap(int &x, int &y);

int globalVar = 10; // Global variable

int main() {
    // Calling the add function
    int sum = add(6, 3);
    std::cout << "Sum: " << sum << std::endl;

    // Demonstrating parameter passing by reference
    int a = 5;
    int b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    // Demonstrating variable scope
    int localVar = 20; // Local variable
    std::cout << "Global variable: " << globalVar << std::endl;
    std::cout << "Local variable: " << localVar << std::endl;

    return 0;
}

// Function definition
int add(int x, int y) {
    return x + y;
}

// Function definition with parameter passing by reference
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
