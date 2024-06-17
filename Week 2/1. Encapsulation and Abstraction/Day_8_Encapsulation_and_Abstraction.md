Sure! Let's include the theoretical aspects of encapsulation, abstraction, and their implementations in C++.

## Week 2, Day 1: Encapsulation and Abstraction

### 1. Encapsulation

**Theory:**
- **Encapsulation** is one of the fundamental principles of object-oriented programming (OOP). It refers to the bundling of data (attributes) and methods (functions) that operate on the data into a single unit or class.
- **Data Hiding**: By keeping the data (attributes) private and providing public methods to access and modify that data, we can hide the internal state of the object from the outside world. This prevents external code from directly accessing and modifying the data, which can help in maintaining the integrity and security of the data.

**Example Code:**
```cpp
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
```

### 2. Accessors and Mutators (Getters and Setters)

**Theory:**
- **Accessors (Getters)**: Methods that return the value of a private attribute.
- **Mutators (Setters)**: Methods that set or update the value of a private attribute. They can also include validation to ensure the integrity of the data.

**Example Code:**
The example code provided in the encapsulation section includes getters and setters.

### 3. Abstraction

**Theory:**
- **Abstraction** is another fundamental principle of OOP. It involves hiding the complex implementation details and showing only the essential features of the object. It allows us to focus on what an object does rather than how it does it.
- **Abstract Classes**: A class that cannot be instantiated and is designed to be inherited by other classes. It usually contains at least one pure virtual function.
- **Pure Virtual Functions**: A virtual function that has no implementation in the base class and must be overridden in derived classes.

**Example Code:**

```cpp
#include <iostream>
#include <cmath>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function providing interface framework.
    virtual double area() const = 0; // Area is a pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Override area function
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override area function
    double area() const override {
        return width * height;
    }
};

int main() {
    // Create objects of derived classes
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);

    // Output the area of the shapes
    cout << "Circle Area: " << circle->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;

    // Clean up
    delete circle;
    delete rectangle;

    return 0;
}