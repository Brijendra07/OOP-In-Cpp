#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
    static int count;
public:
    const static int num = 5;
    // Constructor
    Rectangle(double w, double h) {
        this->width = w;
        this->height = h;
        count++;
    }
    // Destructor
    ~Rectangle() {
        count--;
    }
    // Member functions
    double area() {
        return width * height;
    }
    double perimeter() {
        return 2 * (width + height);
    }
    // Static member function
    static int getCount() {
        return count;
    }
};

// Initialize static member
int Rectangle::count = 0;

int main() {
    {
        Rectangle rect1(4.0, 5.0);
        Rectangle rect2(6.0, 7.0);

        cout << "Area of rect1: " << rect1.area() << endl;
        cout << "Perimeter of rect1: " << rect1.perimeter() << endl;
        cout << "Area of rect2: " << rect2.area() << endl;
        cout << "Perimeter of rect2: " << rect2.perimeter() << endl;

        cout << "Number of Rectangle objects created: " << Rectangle::getCount() << endl;
        cout << "Constant public static member: " << Rectangle::num << endl;
    } // rect1 and rect2 go out of scope here and are destructed

    // Print count after destruction
    cout << "Number of Rectangle objects after destruction: " << Rectangle::getCount() << endl;

    return 0;
}
