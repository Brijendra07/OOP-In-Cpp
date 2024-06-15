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
