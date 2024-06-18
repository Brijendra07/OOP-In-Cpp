#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    virtual void speak() const {
        cout << name << " makes a sound." << endl;
    }

    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Animal() {} // Virtual destructor for proper cleanup of derived classes
};

// Single Inheritance
class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}

    void speak() const override {
        cout << name << " barks." << endl;
    }
};

// Single Inheritance
class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}

    void speak() const override {
        cout << name << " meows." << endl;
    }
};

// Multilevel Inheritance
class Mammal : public Animal {
public:
    Mammal(string n, int a) : Animal(n, a) {}

    void feedMilk() const {
        cout << name << " feeds milk to its young ones." << endl;
    }
};

class Bat : public Mammal {
public:
    Bat(string n, int a) : Mammal(n, a) {}

    void speak() const override {
        cout << name << " screeches." << endl;
    }

    void fly() const {
        cout << name << " flies in the sky." << endl;
    }
};

// Multiple Inheritance
class CanFly {
public:
    virtual void fly() const = 0; // Pure virtual function
};

class Bird : public Animal, public CanFly {
public:
    Bird(string n, int a) : Animal(n, a) {}

    void speak() const override {
        cout << name << " chirps." << endl;
    }

    void fly() const override {
        cout << name << " flies high in the sky." << endl;
    }
};

// Hierarchical Inheritance
class Fish : public Animal {
public:
    Fish(string n, int a) : Animal(n, a) {}

    void speak() const override {
        cout << name << " does not make a sound." << endl;
    }

    void swim() const {
        cout << name << " swims in the water." << endl;
    }
};

class Shark : public Fish {
public:
    Shark(string n, int a) : Fish(n, a) {}

    void speak() const override {
        cout << name << " does not make a sound but is fierce." << endl;
    }

    void hunt() const {
        cout << name << " hunts other fish." << endl;
    }
};

// Hybrid Inheritance
class Duck : public Animal, public CanFly {
public:
    Duck(string n, int a) : Animal(n, a) {}

    void speak() const override {
        cout << name << " quacks." << endl;
    }

    void fly() const override {
        cout << name << " flies short distances." << endl;
    }

    void swim() const {
        cout << name << " swims in the pond." << endl;
    }
};

int main() {
    // Single Inheritance
    Dog dog("Rex", 5);
    Cat cat("Whiskers", 3);

    // Multilevel Inheritance
    Bat bat("Bruce", 2);

    // Multiple Inheritance
    Bird bird("Tweety", 1);

    // Hierarchical Inheritance
    Fish fish("Goldie", 1);
    Shark shark("Jaws", 7);

    // Hybrid Inheritance
    Duck duck("Donald", 4);

    // Displaying information about the animals
    dog.displayInfo();
    dog.speak();

    cat.displayInfo();
    cat.speak();

    bat.displayInfo();
    bat.speak();
    bat.fly();

    bird.displayInfo();
    bird.speak();
    bird.fly();

    fish.displayInfo();
    fish.speak();
    fish.swim();

    shark.displayInfo();
    shark.speak();
    shark.hunt();

    duck.displayInfo();
    duck.speak();
    duck.fly();
    duck.swim();

    return 0;
}
