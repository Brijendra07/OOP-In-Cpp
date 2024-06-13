**Day 4: Custom Datatypes**
- **Structs in C++**
  - **Definition and Usage**: Learn what structs are and how to define them. Understand their purpose and how they can be used to group related variables.
  - **Structs vs Classes**: Understand the differences between structs and classes, particularly focusing on default access specifiers.
- **Enums in C++**
  - **Definition and Usage**: Learn what enums are and how to define them. Understand their purpose and how they can make code more readable.
  - **Strongly Typed Enums (enum class)**: Understand the differences between traditional enums and strongly typed enums introduced in C++11.

### Structs in C++

#### Definition and Usage
A struct in C++ is a user-defined data type that allows grouping of variables of different types under a single name. This can be particularly useful for organizing complex data structures.

```cpp
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    float height;
};

int main() {
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.height = 5.5;

    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Height: " << person1.height << endl;

    return 0;
}
```

#### Structs vs Classes
- In structs, members are public by default.
- In classes, members are private by default.

```cpp
struct MyStruct {
    int a; // public by default
};

class MyClass {
    int b; // private by default
public:
    void setB(int value) {
        b = value;
    }
    int getB() {
        return b;
    }
};
```

### Enums in C++

#### Definition and Usage
An enum (short for "enumeration") is a user-defined data type that consists of a set of named integral constants. They can help make code more readable and maintainable.

```cpp
#include <iostream>
using namespace std;

enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = GREEN;

    switch (myColor) {
        case RED:
            cout << "Color is Red" << endl;
            break;
        case GREEN:
            cout << "Color is Green" << endl;
            break;
        case BLUE:
            cout << "Color is Blue" << endl;
            break;
    }

    return 0;
}
```

#### Strongly Typed Enums (enum class)
C++11 introduced strongly typed enums to address some of the shortcomings of traditional enums. They provide better type safety and scope.

```cpp
#include <iostream>
using namespace std;

enum class Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    Color myColor = Color::GREEN;

    switch (myColor) {
        case Color::RED:
            cout << "Color is Red" << endl;
            break;
        case Color::GREEN:
            cout << "Color is Green" << endl;
            break;
        case Color::BLUE:
            cout << "Color is Blue" << endl;
            break;
    }

    return 0;
}
```

### Key Differences

1. **Type Safety**: Strongly typed enums ensure type safety by causing compile-time errors if an incorrect type is used, preventing accidental misuse.

2. **No Implicit Conversion**: Strongly typed enums do not implicitly convert to integers, avoiding unintended conversions and enhancing code clarity.

3. **Scoped Enumerators**: Enumerator names are scoped within their respective enum types, reducing the risk of name clashes and making the code more maintainable and readable.