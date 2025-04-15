#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>

// Represents a single item in inventory
struct Item {
    std::string name;     // Name of the item
    int quantity;         // Current stock quantity
    int capacity;         // Maximum capacity allowed
};

// Represents a category containing multiple items
struct Category {
    std::string name;           // Category name
    std::vector<Item> items;    // List of items in this category
};

// Declared the categories vector
extern vector<Category> categories;

#endif // MODELS_H

