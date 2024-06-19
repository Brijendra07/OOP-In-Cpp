## Week 2, Day 3: Polymorphism

### Topics to Cover:
1. **Concept of Polymorphism:**
    - Understand the concept of polymorphism in OOP.
    - Learn the difference between compile-time polymorphism and runtime polymorphism.

2. **Compile-Time Polymorphism:**
    - Function overloading
    - Operator overloading

3. **Runtime Polymorphism:**
    - Virtual functions
    - Pointers and references to base class

4. **Abstract Classes and Interfaces:**
    - Understand abstract classes and pure virtual functions.

### Detailed Theory and Examples:

### 1. Concept of Polymorphism

**Theory:**
- **Polymorphism** allows objects to be treated as instances of their parent class rather than their actual class. It enables one interface to be used for a general class of actions, making it easier to extend and maintain code.

### 2. Compile-Time Polymorphism

**Theory:**
- **Compile-time polymorphism** is achieved through function overloading and operator overloading. It is resolved during the compilation of the program.

#### Function Overloading

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }

    void show(double d) {
        cout << "Double: " << d << endl;
    }

    void show(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print obj;
    obj.show(5);
    obj.show(5.5);
    obj.show("Hello, World!");
    return 0;
}
```

#### Operator Overloading

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(1.0, 2.0);
    Complex c3 = c1 + c2; // Using overloaded + operator
    c3.display();
    return 0;
}
```

### 3. Runtime Polymorphism

**Theory:**
- **Runtime polymorphism** is achieved through inheritance and virtual functions. It is resolved during runtime.

#### Virtual Functions

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show function." << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function." << endl;
    }
};

int main() {
    Base* b;
    Derived d;
    b = &d;

    b->show(); // Calls Derived class show function
    return 0;
}
```

### 4. Abstract Classes and Interfaces

**Theory:**
- **Abstract classes** are classes that cannot be instantiated and are designed to be inherited by other classes. They often contain pure virtual functions, which must be implemented by derived classes.

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;
    return 0;
}
```

### Summary

1. **Polymorphism:** Understand and implement both compile-time and runtime polymorphism.
2. **Compile-Time Polymorphism:** Implement function overloading and operator overloading.
3. **Runtime Polymorphism:** Use virtual functions and pointers to base class.
4. **Abstract Classes and Interfaces:** Define abstract classes with pure virtual functions and implement them in derived classes.