#include "display.h"
#include "splashkit.h"
#include "models.h"
#include "status.h"
#include "utils.h"
#include <string>
#include <vector>
// iostream not strictly needed if using splashkit I/O consistently

/**
 * @brief the main menu of the inventory tracking system.
 * Lists available categories or a message if none exist.
 * Provides options to create a new category or exit.
 */
void display_main_menu() {
    clear_console(); // Clear console for a fresh screen
    write_line("=== Inventory Tracking System ===");

    if (categories.empty()) { // Accessing global 'categories' from models.h (via main.cpp definition)
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
 * @brief Displays the menu for a specific category.
 * Shows a table of items with their stock status (quantity/capacity and level).
 * Provides options to manage items within the category.
 * @param category A reference to the Category object to display.
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

            // Get color + status text from status.h/cpp
            auto status_info = get_stock_status(item.quantity, item.capacity);
            std::string status_str = std::to_string(item.quantity) + "/" + std::to_string(item.capacity) + " " + status_info.second;

            // Format the table row with alignment
            std::string line = "| ";
            line += std::to_string(i + 1);
            line += std::string(9 - std::to_string(i + 1).length(), ' '); // Padding for Item No.
            line += "| ";
            line += item.name;
            line += std::string(10 - item.name.length(), ' ');            // Padding for Name
            line += "| ";
            line += status_info.first; // Apply color
            line += status_str;
            // Padding for Stock Status, accounting for color codes not taking visible space
            // This calculation might need adjustment if color codes affect perceived length for padding.
            
            int visible_status_str_length = status_str.length();
            line += std::string(18 - visible_status_str_length, ' ');
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
