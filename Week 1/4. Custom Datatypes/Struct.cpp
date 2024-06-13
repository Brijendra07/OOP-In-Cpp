#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    float height;
};

int main() {
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.height = 5.5;

    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Height: " << person1.height << endl;

    return 0;
}
