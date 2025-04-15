#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>
#include <iostream>
#include "splashkit.h"
#include "models.h"
#include "status.h"
#include "utils.h"

using std::string;
using std::vector;

/**
 * Display the main menu listing all available categories,
 * along with options to create a new one or exit.
 */
void display_main_menu() {
    clear_console(); // Clear console for a fresh screen

    write_line("=== Inventory Tracking System ===");

    if (categories.empty()) {
        write_line("(No categories available)");
    } else {
        // List each category with a number
        for (int i = 0; i < categories.size(); ++i) {
            write_line(std::to_string(i + 1) + ". " + categories[i].name);
        }
        
        #endif // DISPLAY_H
    }

    write_line("---------------------------------");
    write_line("Create New Category (C)");
    write_line("Exit Program (X)");
    write("Enter your choice: ");
}



