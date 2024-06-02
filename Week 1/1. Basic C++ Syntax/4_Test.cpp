#include<bits/stdc++.h>
using namespace std;

// Questions

// Variables and Data Types:

// Que : What is the difference between a variable and a constant in C++?
// Ans : The value of variable can be modified anywhere in the code, whereas we can't modify the 
//       constant values. Constants are declared once in the program.


// Que : Name three basic data types in C++ and provide an example of each.
// Ans : The basic data types are : int (integer), float, bool, char, string, etc.



// Control Structures:

// Que : Describe the difference between a while loop and a do-while loop.
// Ans : While loop only executes when the condition is true, but do-while loop still executes once 
//       if the condition is false.


// Que : What is the purpose of a switch statement, and when would you use it instead of an if-else statement?
// Ans : When there is one variable and based on its value, we have multiple situations, then rather than using 
//       if-else nested loops we can use switch statement.

// Functions and Scope:

// Que : Explain the difference between passing a parameter by value and by reference.
// Ans : If we pass a parameter by value, then it passes a copy of the parameter, so if we change its value using
//       functions, it won't change globally; it only changes the value of the copy, but if we pass by reference, then
//       value changes globally by function.

// Que : What is a global variable, and how does it differ from a local variable?
// Ans : Local variable can't be accessed anywhere. For example, if we declare a variable inside a function, then
//       it can only be accessible inside that function. On the other hand, global variables can be accessed
//       anywhere in the program.


int multiply(int a, int b);
void swap(int &a, int &b);

int main() {
// Coding Tasks

// Variables and Data Types:

// Declare a constant PI with the value 3.14159.
const float PI = 3.14159; // Changed to const

// Declare an integer variable radius and assign it a value of 5.
int radius = 5;

// Declare a float variable area and calculate the area of a circle using the formula area = PI * radius * radius. Print the result.
float area = PI * radius * radius;
cout << "Area: " << area << endl;

// Control Structures:

// Write a program that prints all the even numbers between 1 and 20 using a for loop.

for (int i = 1; i <= 20; i++) { // Changed start from 1
    if (i % 2 == 0) {
        cout << i << endl;
    }
}

// Write a program that reads a character input from the user and prints a message based on the character 
// using a switch statement. If the character is 'A', print "You entered A". If the character is 'B', 
// print "You entered B". For any other character, print "Unknown character".

cout << "Enter a character: " << endl;
char c;
cin >> c;
switch (c) {
    case 'A':
        cout << "You entered A" << endl;
        break; // Added break
    case 'B':
        cout << "You entered B" << endl;
        break; // Added break
    default:
        cout << "Unknown character" << endl;
        break; // Added break
}

// Demonstrate the use of multiply and swap functions in the main function.
int a = 2;
int b = 10;
cout << "Product: " << multiply(a, b) << endl;

cout << "Before swap:" << endl;
cout << "a: " << a << endl;
cout << "b: " << b << endl;

swap(a, b);

cout << "After swap:" << endl;
cout << "a: " << a << endl;
cout << "b: " << b << endl;

return 0;
}

// Functions and Scope:

// Write a function multiply that takes two integers as parameters and returns their product.
int multiply(int a, int b) {
    int product = a * b;
    return product;
}

// Write a function swap that swaps the values of two integer variables passed by reference.
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
