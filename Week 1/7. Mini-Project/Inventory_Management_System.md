### Mini-Project: Inventory Management System

#### Struct Definition
1. **Define a Struct for Items:**
    - Create a struct named `Item` with the following members:
        - `int id`
        - `std::string name`
        - `double price`
        - `int quantity`

#### Enum Definition
2. **Define an Enum for Categories:**
    - Create an enum class named `Category` with the following values:
        - `ELECTRONICS`
        - `GROCERY`
        - `CLOTHING`
        - `BEAUTY`

#### Main Functionalities
3. **Functions for Inventory Management:**
    - **Add Item Function:**
        - Create a function `void addItem(std::vector<Item>& inventory, const Item& item)` to add an item to the inventory.
    - **Display Inventory Function:**
        - Create a function `void displayInventory(const std::vector<Item>& inventory)` to display all items in the inventory.
    - **Search Item by ID Function:**
        - Create a function `Item* searchItemById(std::vector<Item>& inventory, int id)` to search for an item by its ID and return a pointer to the item.
    - **Update Item Function:**
        - Create a function `void updateItem(Item* item, const std::string& name, double price, int quantity)` to update the details of an item.
    - **Remove Item Function:**
        - Create a function `void removeItem(std::vector<Item>& inventory, int id)` to remove an item from the inventory by its ID.

#### Custom Data Types
4. **Usage of Structs and Enums:**
    - Use the `Item` struct and `Category` enum in your functions to manage the inventory.

#### STL Containers
5. **Using Vectors and Maps:**
    - **Vector for Inventory:**
        - Use a `std::vector<Item>` to store the inventory items.
    - **Map for Categories:**
        - Use a `std::map<Category, std::vector<Item>>` to categorize items.

#### Main Function Implementation
6. **Main Function:**
    - Implement the main function to demonstrate the following:
        - Adding items to the inventory.
        - Displaying the inventory.
        - Searching for an item by ID.
        - Updating an item's details.
        - Removing an item from the inventory.
        - Categorizing items and displaying items by category.