### Week 1, Day 3: Advanced Class Features

Today, we'll dive into advanced class features in C++. Let's cover the following topics:

1. **Constructors and Destructors**
2. **Member Functions and Data Members**
3. **Access Specifiers (public, private, protected)**
4. **Static Members**
5. **This Pointer**

#### 1. Constructors and Destructors

**Constructor:**
- Special member function that is automatically called when an object is created.
- Used to initialize objects.

```cpp
class MyClass {
public:
    int data;
    // Constructor
    MyClass(int value) {
        data = value;
    }
};
```

**Destructor:**
- Special member function that is automatically called when an object is destroyed.
- Used for cleanup.

```cpp
class MyClass {
public:
    int data;
    // Constructor
    MyClass(int value) {
        data = value;
    }
    // Destructor
    ~MyClass() {
        // Cleanup code
    }
};
```

#### 2. Member Functions and Data Members

**Member Functions:**
- Functions that are defined within a class.
- Can be defined inside or outside the class definition.

```cpp
class MyClass {
public:
    int data;
    void setData(int value) {
        data = value;
    }
    int getData() {
        return data;
    }
};
```

**Data Members:**
- Variables that hold data associated with a class and its objects.

```cpp
class MyClass {
public:
    int data;
};
```

#### 3. Access Specifiers

**Public:**
- Members are accessible from outside the class.

**Private:**
- Members are accessible only from within the class.

**Protected:**
- Members are accessible from within the class and derived classes.

```cpp
class MyClass {
private:
    int privateData;
protected:
    int protectedData;
public:
    int publicData;
    void setPrivateData(int value) {
        privateData = value;
    }
    int getPrivateData() {
        return privateData;
    }
};
```

#### 4. Static Members

**Static Data Members:**
- Shared by all objects of the class.
- Can be accessed without creating an object.

```cpp
class MyClass {
public:
    static int staticData;
    static void setStaticData(int value) {
        staticData = value;
    }
};

// Definition of static member
int MyClass::staticData = 0;
```

#### 5. This Pointer

- Implicit pointer available in all non-static member functions.
- Points to the object for which the member function is called.

```cpp
class MyClass {
public:
    int data;
    void setData(int data) {
        this->data = data; // Using 'this' pointer to refer to the object's data member
    }
};
```

### Practice Task

Create a class called `Rectangle` that includes the following:
- Data members for width and height (private).
- Constructor to initialize the width and height.
- Public member functions to calculate the area and perimeter.
- Use of `this` pointer.
- Static member function to count the number of rectangle objects created.

#### Example Code:

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
    static int count;
public:
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
    Rectangle rect1(4.0, 5.0);
    Rectangle rect2(6.0, 7.0);

    cout << "Area of rect1: " << rect1.area() << endl;
    cout << "Perimeter of rect1: " << rect1.perimeter() << endl;
    cout << "Area of rect2: " << rect2.area() << endl;
    cout << "Perimeter of rect2: " << rect2.perimeter() << endl;

    cout << "Number of Rectangle objects created: " << Rectangle::getCount() << endl;

    return 0;
}
```

Practice these concepts by creating and manipulating objects, using different access specifiers, and implementing static members. This will reinforce your understanding of advanced class features.