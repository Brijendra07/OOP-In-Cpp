#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    // Constructor
    Person(string name, int age, string address) {
        this->name = name;
        this->age = age;
        this->address = address;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(const string& name) {
        this->name = name;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age with validation
    void setAge(int age) {
        if (age >= 0) {
            this->age = age;
        } else {
            cout << "Invalid age" << endl;
        }
    }

    // Getter for address
    string getAddress() const {
        return address;
    }

    // Setter for address
    void setAddress(const string& address) {
        this->address = address;
    }
};

int main() {
    // Create a Person object
    Person person("John Doe", 30, "123 Main St");

    // Access and modify properties using getters and setters
    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;
    cout << "Address: " << person.getAddress() << endl;

    person.setName("Jane Doe");
    person.setAge(25);
    person.setAddress("456 Elm St");

    cout << "Updated Name: " << person.getName() << endl;
    cout << "Updated Age: " << person.getAge() << endl;
    cout << "Updated Address: " << person.getAddress() << endl;

    return 0;
}
