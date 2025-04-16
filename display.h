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
        
      
    }

    write_line("---------------------------------");
    write_line("Create New Category (C)");
    write_line("Exit Program (X)");
    write("Enter your choice: ");
}

/**
 * Displays all items in the selected category,
 * showing stock levels and color-coded status.
 */
void display_category_menu(Category &category) {
    clear_console(); // Clear screen for neat display

    write_line("=== Category: " + category.name + " ===");
    write_line("---------------------------------------------");
    write_line("| Item No. | Name      | Stock Status      |");
    write_line("|----------|-----------|-------------------|");

    if (category.items.empty()) {
        write_line("|          (No items in category)         |");
    } else {
        for (int i = 0; i < category.items.size(); ++i) {
            Item &item = category.items[i];

            // Get color + status text
            auto status = get_stock_status(item.quantity, item.capacity);
            string status_str = std::to_string(item.quantity) + "/" + std::to_string(item.capacity) + " " + status.second;

            // Format the table row with alignment
            string line = "| ";
            line += std::to_string(i + 1);
            line += string(9 - std::to_string(i + 1).length(), ' ');
            line += "| ";
            line += item.name;
            line += string(10 - item.name.length(), ' ');
            line += "| ";
            line += status.first; // Apply color
            line += status_str;
            line += string(18 - status_str.length(), ' ');
            line += MY_COLOR_RESET; // Reset color
            line += "|";

            write_line(line);
        }
    }

    write_line("---------------------------------------------");
    write_line("\nOptions:");
    write_line("Q - Change Quantity");
    write_line("C - Change Capacity");
    write_line("A - Add Item");
    write_line("R - Remove Item");
    write_line("X - Back to Main Menu");
    write("Enter your choice: ");
}

#endif // DISPLAY_H

