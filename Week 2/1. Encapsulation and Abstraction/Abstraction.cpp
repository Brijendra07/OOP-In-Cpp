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
    Circle(double r) {
        this->radius = r;
    }

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
    // // Constructor using initializer list (shorthand way)
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
