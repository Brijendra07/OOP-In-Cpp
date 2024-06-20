#include <iostream>
#include <string>
using namespace std;

// Base class with a virtual destructor and pure virtual function
class Shape {
public:
    Shape() {
        cout << "Shape Constructor" << endl;
    }
    virtual ~Shape() {
        cout << "Shape Destructor" << endl;
    }
    virtual void draw() const = 0; // Pure virtual function
};

// Derived class Circle
class Circle : public Shape {
public:
    Circle() {
        cout << "Circle Constructor" << endl;
    }
    ~Circle() {
        cout << "Circle Destructor" << endl;
    }
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

// Derived class Square
class Square : public Shape {
public:
    Square() {
        cout << "Square Constructor" << endl;
    }
    ~Square() {
        cout << "Square Destructor" << endl;
    }
    void draw() const override {
        cout << "Drawing Square" << endl;
    }
};

// Type Identification and Casting Examples
void demonstrateCasting() {
    // dynamic_cast example
    Shape* shapePtr = new Circle();
    Circle* circlePtr = dynamic_cast<Circle*>(shapePtr);
    if (circlePtr) {
        circlePtr->draw(); // Calls Circle's draw function
    }

    // static_cast example
    int a = 10;
    double b = static_cast<double>(a) / 3;
    cout << "b: " << b << endl; // Outputs: b: 3.33333

    // reinterpret_cast example
    int x = 65;
    char* p = reinterpret_cast<char*>(&x);
    cout << "Interpreted char value: " << *p << endl; // Might print 'A' on systems using ASCII

    // const_cast example
    const int y = 10;
    int* pY = const_cast<int*>(&y);
    *pY = 20; // Modifying const variable (undefined behavior)
    cout << "Modified value: " << *pY << endl;

    delete shapePtr;
}

int main() {
    // Creating objects of derived classes
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    // Using the objects
    shape1->draw();
    shape2->draw();

    // Deleting the objects (invokes virtual destructors)
    delete shape1;
    delete shape2;

    // Demonstrate Casting
    demonstrateCasting();

    return 0;
}
