#include "category_actions.h"
#include "splashkit.h"
#include "models.h"
#include "utils.h"
#include <string>
#include <vector>

/**
 * @brief Adds a new category to the global list of categories.
 * Prompts the user for a category name.
 * Validates that the name is not empty and does not already exist.
 */
void add_new_category() {
    clear_console();
    write_line("=== Create New Category ===");
    write("- Enter Category Name: ");
    std::string name = read_line();

    bool exists = false;
    // Check if category already exists in the global 'categories' vector
    for (const auto &cat : categories) {
        if (cat.name == name) {
            exists = true;
            break;
        }
    }

    if (name.empty()) {
         write_line("[Error: Category name cannot be empty.]");
    } else if (exists) {
        write_line("[Error: Category '" + name + "' already exists.]");
    }
    else {
        Category new_category;
        new_category.name = name;
        categories.push_back(new_category); // Add to global 'categories'
        write_line("[New Category '" + name + "' Created]");
    }
    write_line("\nPress Enter to continue...");
    read_line(); // Pause for user
}

/**
 * @brief Adds a new item to the specified category.
 * Prompts for item name, capacity, and quantity.
 * Validates inputs: name not empty, name uniqueness within category,
 * positive capacity, and quantity within [0, capacity].
 * @param category A reference to the Category object to add the item to.
 */
void add_item_to_category(Category &category) {
    write_line("\n--- Add Item ---");
    write("- Enter Name: ");
    std::string name = read_line();

    int capacity = -1;
    // Loop until a positive capacity is entered
    while (capacity <= 0) {
         capacity = read_integer("- Enter Capacity: ");
         if (capacity <= 0) write_line("Capacity must be positive.");
    }

    int quantity = -1;
    // Loop until a valid quantity (0 to capacity) is entered
     while (quantity < 0 || quantity > capacity) {
        quantity = read_integer("- Enter Quantity: ");
         if (quantity < 0) write_line("Quantity cannot be negative.");
         if (quantity > capacity) write_line("Quantity cannot exceed capacity (" + std::to_string(capacity) + ").");
     }

     bool exists = false;
     // Check if item name already exists in this category
     for(const auto& item : category.items) {
         if (item.name == name) {
             exists = true;
             break;
         }
     }

    if (name.empty()) {
        write_line("[Error: Item name cannot be empty.]");
    } else if (exists) {
        write_line("[Error: Item '" + name + "' already exists in this category.]");
    } else {
        Item new_item;
        new_item.name = name;
        new_item.quantity = quantity;
        new_item.capacity = capacity;
        category.items.push_back(new_item);
        write_line("[Added: " + name + " " + std::to_string(quantity) + "/" + std::to_string(capacity) + "]");
    }
}

/**
 * @brief Removes an item from the specified category.
 * Prompts the user to select an item by number.
 * @param category A reference to the Category object to remove the item from.
 */
void remove_item_from_category(Category &category) {
    if (category.items.empty()) {
        write_line("[No items to remove.]");
        return;
    }
    write_line("\n--- Remove Item ---");
    // read_integer_range ensures valid item number
    int item_no = read_integer_range("- Enter Item No.: ", 1, category.items.size());
    int index = item_no - 1; // Convert to 0-based index

    std::string removed_name = category.items[index].name;
    category.items.erase(category.items.begin() + index); // Remove item from vector

    write_line("[Removed: " + removed_name + "]");
}

/**
 * @brief Changes the quantity of an existing item in the specified category.
 * Prompts for item number and new quantity.
 * Validates new quantity: must be within [0, item.capacity].
 * @param category A reference to the Category object containing the item.
 */
void change_item_quantity(Category &category) {
     if (category.items.empty()) {
        write_line("[No items to modify.]");
        return;
    }
    write_line("\n--- Change Quantity ---");
    int item_no = read_integer_range("- Enter Item No.: ", 1, category.items.size());
    int index = item_no - 1;
    Item &item = category.items[index]; // Get a reference to the item

    int new_quantity = -1;
    // Loop until a valid new quantity is entered
    while (new_quantity < 0 || new_quantity > item.capacity) {
        new_quantity = read_integer("- Enter New Quantity: ");
         if (new_quantity < 0) write_line("Quantity cannot be negative.");
         if (new_quantity > item.capacity) write_line("Quantity cannot exceed capacity (" + std::to_string(item.capacity) + ").");
     }

    item.quantity = new_quantity;
    write_line("[Updated: " + item.name + " now " + std::to_string(item.quantity) + "/" + std::to_string(item.capacity) + "]");
}

/**
 * @brief Changes the capacity of an existing item in the specified category.
 * Prompts for item number and new capacity.
 * Validates new capacity: must be positive.
 * If new capacity is less than current quantity, quantity is adjusted to new capacity.
 * @param category A reference to the Category object containing the item.
 */
void change_item_capacity(Category &category) {
    if (category.items.empty()) {
        write_line("[No items to modify.]");
        return;
    }
    write_line("\n--- Change Capacity ---");
    int item_no = read_integer_range("- Enter Item No.: ", 1, category.items.size());
    int index = item_no - 1;
    Item &item = category.items[index]; // Get a reference to the item

    int new_capacity = -1;
    // Loop until a positive new capacity is entered
    while (new_capacity <= 0) {
         new_capacity = read_integer("- Enter New Capacity: ");
         if (new_capacity <= 0) write_line("Capacity must be positive.");
    }

    // Adjust quantity if it exceeds new capacity
    if (item.quantity > new_capacity) {
        write_line("[Warning: Current quantity (" + std::to_string(item.quantity) + ") exceeds new capacity (" + std::to_string(new_capacity) + "). Adjusting quantity.]");
        item.quantity = new_capacity;
    }

    item.capacity = new_capacity;
    write_line("[Updated: " + item.name + " now " + std::to_string(item.quantity) + "/" + std::to_string(item.capacity) + "]");
}