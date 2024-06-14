### Week 1, Day 5: Built-in Datatypes: Containers in STL

**Topics to Cover:**
1. **Introduction to STL**
   - What is the Standard Template Library (STL)?
   - Benefits of using STL in C++

2. **Vectors**
   - Declaration and Initialization
     ```cpp
     std::vector<int> vec; // Empty vector of integers
     std::vector<int> vec(10); // Vector of 10 integers, all initialized to 0
     std::vector<int> vec = {1, 2, 3, 4, 5}; // Vector initialized with values
     ```
   - Common Operations
     - **Insert**
       ```cpp
       vec.push_back(6); // Adds 6 at the end
       vec.insert(vec.begin() + 2, 10); // Inserts 10 at index 2
       ```
     - **Delete**
       ```cpp
       vec.pop_back(); // Removes last element
       vec.erase(vec.begin() + 2); // Removes element at index 2
       ```
     - **Access**
       ```cpp
       int value = vec[0]; // Accessing element at index 0
       value = vec.at(2); // Accessing element at index 2 with bounds checking
       ```
     - **Size and Capacity**
       ```cpp
       int size = vec.size(); // Number of elements in vector
       int capacity = vec.capacity(); // Current capacity of vector
       ```

3. **Sets**
   - Declaration and Initialization
     ```cpp
     std::set<int> mySet; // Empty set of integers
     std::set<int> mySet = {1, 2, 3, 4, 5}; // Set initialized with values
     ```
   - Common Operations
     - **Insert**
       ```cpp
       mySet.insert(6); // Inserts 6 into the set
       ```
     - **Delete**
       ```cpp
       mySet.erase(2); // Removes element with value 2
       ```
     - **Find**
       ```cpp
       auto it = mySet.find(3); // Finds element with value 3
       if (it != mySet.end()) {
           // Element found
       }
       ```

### Practical Exercises:

1. **Vector Operations:**
   - Create a vector of integers.
   - Perform various insertions and deletions.
   - Access elements and print the size and capacity of the vector.

2. **Set Operations:**
   - Create a set of integers.
   - Insert and delete elements.
   - Find and print elements within the set.

### Example Code:

```cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    // Vector example
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    vec.insert(vec.begin() + 2, 10);
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