## Week 2, Day 2: Inheritance

### 1. Introduction to Inheritance

**Theory:**
- **Inheritance** is a fundamental concept in OOP that allows a class (derived class) to inherit attributes and methods from another class (base class). It promotes code reusability and establishes a natural hierarchy between classes.

**Example Code:**
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void speak() const {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
};

int main() {
    Dog dog;
    dog.speak(); // Inherits and uses speak method from Animal class
    return 0;
}
```

### 2. Types of Inheritance

**Theory:**
- **Single Inheritance:** A derived class inherits from one base class.
- **Multiple Inheritance:** A derived class inherits from more than one base class.
- **Multilevel Inheritance:** A derived class is derived from another derived class.
- **Hierarchical Inheritance:** Multiple classes inherit from a single base class.
- **Hybrid Inheritance:** A combination of two or more types of inheritance.

**Example Code:**

#### Single Inheritance
```cpp
class A {
public:
    void display() const {
        cout << "Class A" << endl;
    }
};

class B : public A {
};

int main() {
    B obj;
    obj.display(); // Inherits and uses display method from A
    return 0;
}
```

#### Multiple Inheritance
```cpp
class A {
public:
    void displayA() const {
        cout << "Class A" << endl;
    }
};

class B {
public:
    void displayB() const {
        cout << "Class B" << endl;
    }
};

class C : public A, public B {
};

int main() {
    C obj;
    obj.displayA(); // Inherits and uses displayA method from A
    obj.displayB(); // Inherits and uses displayB method from B
    return 0;
}
```

#### Multilevel Inheritance
```cpp
class A {
public:
    void display() const {
        cout << "Class A" << endl;
    }
};

class B : public A {
};

class C : public B {
};

int main() {
    C obj;
    obj.display(); // Inherits and uses display method from A through B
    return 0;
}
```

#### Hierarchical Inheritance
```cpp
class A {
public:
    void display() const {
        cout << "Class A" << endl;
    }
};

class B : public A {
};

class C : public A {
};

int main() {
    B objB;
    C objC;
    objB.display(); // Inherits and uses display method from A
    objC.display(); // Inherits and uses display method from A
    return 0;
}
```

#### Hybrid Inheritance
```cpp
class A {
public:
    void displayA() const {
        cout << "Class A" << endl;
    }
};

class B : public A {
};

class C {
public:
    void displayC() const {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
};

int main() {
    D obj;
    obj.displayA(); // Inherits and uses displayA method from A through B
    obj.displayC(); // Inherits and uses displayC method from C
    return 0;
}
```

### 3. Base and Derived Classes

**Theory:**
- **Base Class:** The class being inherited from.
- **Derived Class:** The class that inherits from the base class.
- **Access Specifiers:** Control the access of base class members in derived classes:
  - **public:** Public and protected members of the base class remain public and protected in the derived class.
  - **protected:** Public and protected members of the base class become protected in the derived class.
  - **private:** Public and protected members of the base class become private in the derived class.

**Example Code:**
```cpp
class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}
    void speak() const {
        cout << name << " makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void speak() const override { // Overriding the speak method
        cout << name << " barks." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void speak() const override { // Overriding the speak method
        cout << name << " meows." << endl;
    }
};

int main() {
    Animal genericAnimal("Generic Animal");
    Dog dog("Rex");
    Cat cat("Whiskers");

    genericAnimal.speak(); // Output: Generic Animal makes a sound.
    dog.speak();           // Output: Rex barks.
    cat.speak();           // Output: Whiskers meows.

    return 0;
}
```

### 4. Overriding Member Functions

**Theory:**
- Derived classes can provide specific implementations of methods defined in the base class.
- The `override` keyword ensures that the method is intended to override a base class method.

**Example Code:**
```cpp
class Base {
public:
    virtual void show() const {
        cout << "Base class show function." << endl;
    }
};

class Derived : public Base {
public:
    void show() const override { // Overriding the show method
        cout << "Derived class show function." << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show(); // Output: Derived class show function.

    delete basePtr;
    return 0;
}
```

### Summary

1. **Inheritance:** Enables code reuse and establishes a relationship between base and derived classes.
2. **Types of Inheritance:** Single, multiple, multilevel, hierarchical, and hybrid inheritance.
3. **Base and Derived Classes:** Understand how access specifiers affect inheritance.
4. **Overriding Functions:** Derived classes can override base class methods to provide specific behavior.

By understanding and implementing these concepts, you can create a flexible and reusable class hierarchy in C++.