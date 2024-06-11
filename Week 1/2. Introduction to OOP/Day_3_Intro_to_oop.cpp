#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Method to display person details
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Creating an object of the class
    Person person1;

    // Setting attributes directly
    person1.name = "John";
    person1.age = 30;

    // Accessing class methods
    person1.displayInfo();

    // Modifying object attributes directly
    person1.name = "Jane";
    person1.age = 25;
    person1.displayInfo();

    return 0;
}