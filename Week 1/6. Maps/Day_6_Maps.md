
1. **Maps**
   - Declaration and Initialization
     ```cpp
     std::map<int, std::string> myMap; // Empty map with int keys and string values
     std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}}; // Map initialized with values
     ```
   - Common Operations
     - **Insert**
       ```cpp
       myMap[4] = "four"; // Inserts or updates the key 4 with value "four"
       myMap.insert({5, "five"}); // Inserts key 5 with value "five"
       ```
     - **Delete**
       ```cpp
       myMap.erase(2); // Removes element with key 2
       myMap.clear(); // Removes all elements
       ```
     - **Access**
       ```cpp
       std::string value = myMap[1]; // Accessing value with key 1
       value = myMap.at(3); // Accessing value with key 3, throws exception if key doesn't exist
       ```
     - **Iterate**
       ```cpp
       for (const auto& pair : myMap) {
           std::cout << pair.first << " => " << pair.second << std::endl;
       }
       ```
     - **Size**
       ```cpp
       int size = myMap.size(); // Number of elements in map
       ```

2. **Unordered Maps**
   - Declaration and Initialization
     ```cpp
     std::unordered_map<int, std::string> myUnorderedMap; // Empty unordered map
     std::unordered_map<int, std::string> myUnorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}}; // Unordered map initialized with values
     ```
   - Common Operations
     - **Insert**
       ```cpp
       myUnorderedMap[4] = "four"; // Inserts or updates the key 4 with value "four"
       myUnorderedMap.insert({5, "five"}); // Inserts key 5 with value "five"
       ```
     - **Delete**
       ```cpp
       myUnorderedMap.erase(2); // Removes element with key 2
       myUnorderedMap.clear(); // Removes all elements
       ```
     - **Access**
       ```cpp
       std::string value = myUnorderedMap[1]; // Accessing value with key 1
       value = myUnorderedMap.at(3); // Accessing value with key 3, throws exception if key doesn't exist
       ```
     - **Iterate**
       ```cpp
       for (const auto& pair : myUnorderedMap) {
           std::cout << pair.first << " => " << pair.second << std::endl;
       }
       ```
     - **Size**
       ```cpp
       int size = myUnorderedMap.size(); // Number of elements in unordered map
       ```

3. **Comparison Between Map Types**
   - **Performance**
     - Maps are typically implemented as balanced binary trees (e.g., red-black trees), providing O(log n) complexity for insertions, deletions, and lookups.
     - Unordered maps are implemented using hash tables, providing average O(1) complexity for insertions, deletions, and lookups, but with a potential worst-case of O(n).
   - **Order of Elements**
     - Maps maintain the elements in sorted order based on keys.
     - Unordered maps do not maintain any specific order.

### Example Code:

```cpp
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    // Ordered map example
    std::map<int, std::string> orderedMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    orderedMap[4] = "four";
    orderedMap.insert({5, "five"});
    orderedMap.erase(2);

    std::cout << "Ordered Map:" << std::endl;
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
    std::cout << "Size: " << orderedMap.size() << std::endl;

    // Unordered map example
    std::unordered_map<int, std::string> unorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    unorderedMap[4] = "four";
    unorderedMap.insert({5, "five"});
    unorderedMap.erase(2);

    std::cout << "\nUnordered Map:" << std::endl;
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
    std::cout << "Size: " << unorderedMap.size() << std::endl;

    return 0;
}


```
The key difference between `std::map` and `std::unordered_map` lies in their underlying implementations and the resulting performance characteristics and ordering of elements. Let's break down these differences in detail:

### 1. Underlying Data Structure
- **std::map**:
  - Uses a balanced binary search tree (e.g., Red-Black Tree) as the underlying data structure.
  - Maintains elements in a sorted order based on keys.
  - Provides O(log n) complexity for insertions, deletions, and lookups.

- **std::unordered_map**:
  - Uses a hash table as the underlying data structure.
  - Does not maintain any specific order for elements.
  - Provides average O(1) complexity for insertions, deletions, and lookups, with a worst-case complexity of O(n) if many elements hash to the same bucket (hash collisions).

### 2. Performance Characteristics
- **Insertion, Deletion, and Lookup**:
  - **std::map**: O(log n) complexity due to tree operations.
  - **std::unordered_map**: Average O(1) complexity due to hash table operations, with potential O(n) in worst-case scenarios involving hash collisions.

- **Memory Usage**:
  - **std::map**: Typically uses more memory per element due to the need to store additional pointers for the tree structure.
  - **std::unordered_map**: May use more memory overall due to the overhead of maintaining the hash table, including potential unused space in buckets to reduce collisions.

### 3. Element Ordering
- **std::map**:
  - Elements are stored in sorted order based on the key.
  - Useful when you need to maintain a sorted sequence of elements.

- **std::unordered_map**:
  - Elements are not stored in any particular order.
  - Useful when you need fast access to elements without caring about their order.

### 4. Use Cases
- **std::map**:
  - When you need ordered data.
  - When you frequently need to perform range-based queries (e.g., finding all elements within a certain range of keys).

- **std::unordered_map**:
  - When you need fast access to elements and do not care about their order.
  - When the average-case performance is more important than the worst-case scenario.

### Example Scenarios
- **Using `std::map`**:
  ```cpp
  std::map<int, std::string> myMap;
  myMap[3] = "Three";
  myMap[1] = "One";
  myMap[2] = "Two";

  // Elements will be in order: (1, "One"), (2, "Two"), (3, "Three")
  for (const auto& pair : myMap) {
      std::cout << pair.first << " => " << pair.second << std::endl;
  }
  ```

- **Using `std::unordered_map`**:
  ```cpp
  std::unordered_map<int, std::string> myUnorderedMap;
  myUnorderedMap[3] = "Three";
  myUnorderedMap[1] = "One";
  myUnorderedMap[2] = "Two";

  // Elements may be in any order: (1, "One"), (2, "Two"), (3, "Three")
  for (const auto& pair : myUnorderedMap) {
      std::cout << pair.first << " => " << pair.second << std::endl;
  }
  ```

In summary, while both `std::map` and `std::unordered_map` offer similar functionality in terms of mapping keys to values, they differ significantly in their underlying implementations, performance characteristics, and ordering of elements. Your choice between the two should be based on the specific needs of your application regarding performance and element ordering.