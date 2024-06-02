#include <iostream>

int main() {
    int a = 5;
    float b = 3.14;
    char c = 'A';
    bool d = true;

    std::cout << "Integer: " << a << std::endl;
    std::cout << "Float: " << b << std::endl;
    std::cout << "Char: " << c << std::endl;
    std::cout << "Bool: " << d << std::endl;

    const int MAX = 100;
    std::cout << "Constant MAX: " << MAX << std::endl;
    
    // MAX = 200;    error: assignment of read-only variable (constant) 'MAX'

    return 0;
}
