#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Item {
    int id;
    std::string name;
    double price;
    int quantity;
};

enum class Category {
    ELECTRONICS,
    GROCERY,
    CLOTHING,
    BEAUTY
};

void addItem(std::vector<Item>& inventory, std::map<Category, std::vector<Item>>& categorizedItems, const Item& item, Category category) {
    inventory.push_back(item);
    categorizedItems[category].push_back(item);
}

void displayInventory(const std::vector<Item>& inventory) {
    for (const auto& item : inventory) {
        std::cout << "ID: " << item.id << ", Name: " << item.name
                  << ", Price: " << item.price << ", Quantity: " << item.quantity << std::endl;
    }
}

Item* searchItemById(std::vector<Item>& inventory, int id) {
    for (auto& item : inventory) {
        if (item.id == id) {
            return &item;
        }
    }
    return nullptr;
}

void updateItem(Item* item, const std::string& name, double price, int quantity) {
    if (item) {
        item->name = name;
        item->price = price;
        item->quantity = quantity;
    }
}

void removeItem(std::vector<Item>& inventory, int id) {
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(), [id](Item& item) {
        return item.id == id;
    }), inventory.end());
}

void displayItemsByCategory(const std::map<Category, std::vector<Item>>& categorizedItems) {
    for (const auto& pair : categorizedItems) {
        std::cout << "Category: ";
        switch (pair.first) {
            case Category::ELECTRONICS: std::cout << "Electronics"; break;
            case Category::GROCERY: std::cout << "Grocery"; break;
            case Category::CLOTHING: std::cout << "Clothing"; break;
            case Category::BEAUTY: std::cout << "Beauty"; break;
        }
        std::cout << std::endl;
        displayInventory(pair.second);
    }
}

int main() {
    std::vector<Item> inventory;
    std::map<Category, std::vector<Item>> categorizedItems;

    // Create items
    Item item1 = {1, "Laptop", 999.99, 10};
    Item item2 = {2, "Apple", 0.99, 100};
    Item item3 = {3, "T-shirt", 19.99, 50};
    Item item4 = {4, "Shampoo", 5.99, 30};

    // Add items to inventory and categorize them
    addItem(inventory, categorizedItems, item1, Category::ELECTRONICS);
    addItem(inventory, categorizedItems, item2, Category::GROCERY);
    addItem(inventory, categorizedItems, item3, Category::CLOTHING);
    addItem(inventory, categorizedItems, item4, Category::BEAUTY);

    // Display inventory
    std::cout << "Complete Inventory:\n";
    displayInventory(inventory);

    // Search for an item by ID
    int searchId = 2;
    Item* item = searchItemById(inventory, searchId);
    if (item) {
        std::cout << "Found item with ID " << searchId << ": " << item->name << std::endl;
    } else {
        std::cout << "Item with ID " << searchId << " not found.\n";
    }

    // Update item
    if (item) {
        updateItem(item, "Green Apple", 1.09, 150);
    }

    // Remove item
    removeItem(inventory, 1);

    // Display items by category
    std::cout << "\nCategorized Items:\n";
    displayItemsByCategory(categorizedItems);

    return 0;
}
