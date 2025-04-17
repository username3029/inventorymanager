#ifndef CATEGORY_ACTIONS_H
#define CATEGORY_ACTIONS_H

#include <string>
#include "models.h"
#include "utils.h"

using std::string;

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

#endif // CATEGORY_ACTIONS_H