#ifndef CATEGORY_ACTIONS_H
#define CATEGORY_ACTIONS_H

#include <string>
#include "models.h"
#include "utils.h"
#include "splashkit.h" 

using std::string;
using std::to_string;

/**
 * Adds a new category to the global list.
 * Prompts user for a name and prevents duplicates or empty names.
 */
void add_new_category() {
    clear_console();
    write_line("=== Create New Category ===");

    write("- Enter Category Name: ");
    string name = read_line();

    bool exists = false;

    // Check if category already exists
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
    } else {
        // Add category to list
        Category new_category;
        new_category.name = name;
        categories.push_back(new_category);
        write_line("[New Category '" + name + "' Created]");
    }

    write_line("\nPress Enter to continue...");
    read_line();
}

/**
 * Adds a new item to an existing category.
 * Ensures name uniqueness, valid capacity, and valid quantity.
 */
void add_item_to_category(Category &category) {
    write_line("\n--- Add Item ---");

    write("- Enter Name: ");
    string name = read_line();

    int capacity = -1;
    while (capacity <= 0) {
        capacity = read_integer("- Enter Capacity: ");
        if (capacity <= 0)
            write_line("Capacity must be positive.");
    }

    int quantity = -1;
    while (quantity < 0 || quantity > capacity) {
        quantity = read_integer("- Enter Quantity: ");
        if (quantity < 0)
            write_line("Quantity cannot be negative.");
        if (quantity > capacity)
            write_line("Quantity cannot exceed capacity (" + std::to_string(capacity) + ").");
    }

    // Check if item already exists
    bool exists = false;
    for (const auto &item : category.items) {
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
        // Add item to category
        Item new_item;
        new_item.name = name;
        new_item.quantity = quantity;
        new_item.capacity = capacity;
        category.items.push_back(new_item);
        write_line("[Added: " + name + " " + std::to_string(quantity) + "/" + std::to_string(capacity) + "]");
    }
}

/**
 * Removes an item from the specified category by its index.
 */
void remove_item_from_category(Category &category) {
    if (category.items.empty()) {                     // Check if category is empty
        write_line("[No items to remove.]");
        return;
    }

    write_line("\n--- Remove Item ---");
    int item_no = read_integer_range(                 // Prompt user for item number within valid range
        "- Enter Item No.: ", 1, category.items.size());
    int index = item_no - 1;                          // Convert to 0-based index

    string removed_name = category.items[index].name; // Store item name before removal (for message)
    category.items.erase(category.items.begin() + index); // Remove item from vector

    write_line("[Removed: " + removed_name + "]");    // Confirm deletion to user
}

/**
 * Updates the quantity of an item, ensuring it stays within capacity bounds.
 */
void change_item_quantity(Category &category) {
    if (category.items.empty()) {
        write_line("[No items to modify.]");          // No items to update
        return;
    }

    write_line("\n--- Change Quantity ---");
    int item_no = read_integer_range(
        "- Enter Item No.: ", 1, category.items.size());
    int index = item_no - 1;

    Item &item = category.items[index];               // Reference the item directly

    int new_quantity = -1;
    while (new_quantity < 0 || new_quantity > item.capacity) {
        new_quantity = read_integer("- Enter New Quantity: "); // Ask for new quantity

        if (new_quantity < 0)
            write_line("Quantity cannot be negative.");        // Reject negative values
        if (new_quantity > item.capacity)
            write_line("Quantity cannot exceed capacity (" +
                       std::to_string(item.capacity) + ").");  // Don't allow exceeding capacity
    }

    item.quantity = new_quantity;                     // Save valid new quantity
    write_line("[Updated: " + item.name + " now " +
               std::to_string(item.quantity) + "/" +
               std::to_string(item.capacity) + "]");
}

void change_item_capacity(Category &category) {
    if (category.items.empty()) {
        write_line("[No items to modify.]"); // Exit if no items
        return;
    }

    write_line("\n--- Change Capacity ---");
    int item_no = read_integer_range("- Enter Item No.: ", 1, category.items.size()); // Select item
    int index = item_no - 1; // Convert to index
    Item &item = category.items[index]; // Reference the item

    int new_capacity = -1;
    while (new_capacity <= 0) {
        new_capacity = read_integer("- Enter New Capacity: "); // Prompt user

        if (new_capacity <= 0) {
            write_line("Capacity must be positive."); // Reject invalid input
        }
    }

    if (item.quantity > new_capacity) {
        // If current quantity is above new capacity, adjust it
        write_line("[Warning: Current quantity (" + to_string(item.quantity) +
                   ") exceeds new capacity (" + to_string(new_capacity) + "). Adjusting quantity.]");
        item.quantity = new_capacity; // Auto-adjust to fit new capacity
    }

    item.capacity = new_capacity; // Save updated capacity
    write_line("[Updated: " + item.name + " now " + to_string(item.quantity) +
               "/" + to_string(item.capacity) + "]");
}



#endif // CATEGORY_ACTIONS_H

