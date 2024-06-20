## Week 2, Day 4: More on Polymorphism

### Topics to Cover:
1. **Virtual Destructors:**
    - Understand the need for virtual destructors in base classes.
    
2. **Pure Virtual Functions:**
    - Understand how pure virtual functions enforce the implementation of certain methods in derived classes.

3. **Type Identification and Casting:**
    - Learn about `dynamic_cast`, `static_cast`, `reinterpret_cast`, and `const_cast`.
    - Understand when and how to use these type casting operators.

### Detailed Theory and Examples:

### 1. Virtual Destructors

**Theory:**
- A **virtual destructor** ensures that the destructor of the derived class is called when an object is deleted through a pointer to the base class. This is crucial for proper cleanup of resources in polymorphic base classes.

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor" << endl;
    }
    virtual ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor" << endl;
    }
    ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // Calls Derived destructor, then Base destructor
    return 0;
}
```

### 2. Pure Virtual Functions

**Theory:**
- A **pure virtual function** is a function declared in a base class that has no definition relative to the base class. It forces derived classes to provide an implementation for the function.

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

### 3. Type Identification and Casting

**Theory:**
- **`dynamic_cast`:** Safely casts a pointer/reference to a base class to a pointer/reference to a derived class.
- **`static_cast`:** Performs a compile-time cast that does not check the types.
- **`reinterpret_cast`:** Casts a pointer to any other type of pointer.
- **`const_cast`:** Adds or removes the `const` qualifier from a variable.

#### `dynamic_cast` Example:

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function." << endl;
    }
};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);
    if (d != nullptr) {
        d->show(); // Calls Derived's show function
    } else {
        cout << "Failed to cast Base* to Derived*" << endl;
    }
    delete b;
    return 0;
}
```

#### `static_cast` Example:

**Example Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = static_cast<double>(a) / 3;
    cout << "b: " << b << endl; // Outputs: b: 3.33333
    return 0;
}
```

#### `reinterpret_cast` Example:

**Example Code:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 65;
    char* p = reinterpret_cast<char*>(&a);
    cout << *p << endl; // Outputs 'A' if system uses ASCII
    return 0;
}
```

#### `const_cast` Example:

**Example Code:**
```cpp
#include <iostream>
using namespace std;

void print(int* p) {
    cout << *p << endl;
}

int main() {
    const int a = 10;
    print(const_cast<int*>(&a));
    return 0;
}
```

The simplest definition of casting in programming is:

### Casting
**Casting** is the process of converting a variable from one type to another.

### Example:
In C++, you can use different types of casting to convert between types.

- **Static Cast:**
  Converts between compatible types.
  ```cpp
  int a = 10;
  double b = static_cast<double>(a); // Converts int to double
  ```

- **Dynamic Cast:**
  Safely converts pointers/references to base class types to pointers/references to derived class types.
  ```cpp
  Base* basePtr = new Derived();
  Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Safely converts Base* to Derived*
  ```

- **Reinterpret Cast:**
  Reinterprets the bit pattern of the variable as another type.
  ```cpp
  int a = 65;
  char* p = reinterpret_cast<char*>(&a); // Reinterprets int* as char*
  ```

- **Const Cast:**
  Adds or removes the `const` qualifier from a variable.
  ```cpp
  const int a = 10;
  int* p = const_cast<int*>(&a); // Removes constness
  ```

### Summary:
Casting is used to convert a variable from one type to another, and it can be done using various casting operators in C++ to achieve the desired type conversion.

### Summary

1. **Virtual Destructors:** Ensure proper cleanup of derived class objects.
2. **Pure Virtual Functions:** Enforce derived classes to implement specific functions.
3. **Type Identification and Casting:** Use various casting operators for different needs.