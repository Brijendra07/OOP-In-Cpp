#include <iostream>
#include <vector>
#include <set>

int main() {
    // Vector example
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    vec.insert(vec.begin() + 2, 10);

    vec.pop_back();
    vec.erase(vec.begin() + 3);

    std::cout << "Vector elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // Set example
    std::set<int> mySet = {1, 2, 3, 4, 5};
    mySet.insert(6);
    mySet.erase(2);

    std::cout << "Set elements: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }

    auto it = mySet.find(3);
    if (it != mySet.end()) {
        std::cout << "\nElement 3 found in the set." << std::endl;
    } else {
        std::cout << "\nElement 3 not found in the set." << std::endl;
    }

    return 0;
}
