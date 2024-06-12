### Day 3: Introduction to OOP Concepts

#### 1. Understanding OOP
- **Definition**: Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects", which are instances of classes.
- **Advantages**:
  - **Modularity**: Dividing programs into objects and classes makes code more modular and easier to manage.
  - **Reusability**: Classes can be reused in different programs, promoting code reuse.
  - **Ease of Maintenance**: Easier to modify and maintain existing code.
  - **Real-world Modeling**: Objects can model real-world entities, making programs more intuitive.

#### 2. Basic OOP Concepts
- **Class and Object**:
  - **Class**: A blueprint for creating objects. It defines attributes and methods.
  - **Object**: An instance of a class.
- **Attributes and Methods**:
  - **Attributes**: Data members of a class (variables that hold data).
  - **Methods**: Functions defined inside a class that operate on the attributes.

#### 3. Creating Classes and Objects in C++
- **Class Declaration**:
  ```cpp
  class ClassName {
  public:
      // Public attributes and methods
      int attribute;
      void method();
  };
  ```
- **Defining Member Functions**:
  - Inside the class:
    ```cpp
    class Person {
    public:
        void displayInfo() {
            cout << "Displaying information" << endl;
        }
    };
    ```
  - Outside the class:
    ```cpp
    class Person {
    public:
        void displayInfo();
    };

    void Person::displayInfo() {
        cout << "Displaying information" << endl;
    }
    ```
- **Creating Objects and Accessing Members**:
  ```cpp
  Person person1; // Creating an object
  person1.displayInfo(); // Calling a method
  ```

#### Example Code

Here’s a simple example to illustrate these concepts:
```cpp
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
```

### Summary
Today, you've been introduced to the fundamental concepts of OOP, including classes, objects, attributes, and methods. You also learned how to create classes and objects in C++, and how to define and access class methods. These concepts form the foundation of OOP and are essential for building complex and efficient C++ programs. Practice by creating your own classes and experimenting with these features to strengthen your understanding.