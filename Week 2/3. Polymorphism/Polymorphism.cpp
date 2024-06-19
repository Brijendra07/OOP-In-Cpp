#include <iostream>
#include <string>
using namespace std;

// Function Overloading Example
class Print {
public:
    void show(int i) {
        cout << "Integer: " << i << endl;
    }

    void show(double d) {
        cout << "Double: " << d << endl;
    }

    void show(const string& s) {
        cout << "String: " << s << endl;
    }
};

// Operator Overloading Example
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

    void display() const {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

// Base class with virtual function for Runtime Polymorphism
class Base {
public:
    virtual void show() const {
        cout << "Base class show function." << endl;
    }
};

// Derived class overriding virtual function
class Derived : public Base {
public:
    void show() const override {
        cout << "Derived class show function." << endl;
    }
};

// Abstract Class with pure virtual function
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
};

// Derived class implementing pure virtual function
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

// Another derived class implementing pure virtual function
class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    // Compile-Time Polymorphism: Function Overloading
    Print printer;
    printer.show(5);
    printer.show(5.5);
    printer.show("Hello, World!");

    // Compile-Time Polymorphism: Operator Overloading
    Complex c1(3.0, 4.0), c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    c3.display();

    // Runtime Polymorphism: Virtual Functions
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    basePtr->show(); // Calls Derived class show function

    // Abstract Classes and Interfaces
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;

    return 0;
}
