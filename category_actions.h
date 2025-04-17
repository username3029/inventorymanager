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

#endif // CATEGORY_ACTIONS_H