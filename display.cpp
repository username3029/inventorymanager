#include "display.h"
#include "splashkit.h"      
#include "models.h"         // For Category, Item, and global 'categories' vector
#include "status.h"         // For get_stock_status, MY_COLOR_RESET
#include "utils.h"          // For clear_console
#include <string>           // For std::string, std::to_string
#include <vector>           // For std::vector (used with categories.items)


void display_main_menu() {
    clear_console();
    write_line("=== Inventory Tracking System ===");

    if (categories.empty()) { // Accessing global 'categories'
        write_line("(No categories available)");
    } else {
        for (int i = 0; i < categories.size(); ++i) {
            write_line(std::to_string(i + 1) + ". " + categories[i].name);
        }
    }

    write_line("---------------------------------");
    write_line("Create New Category (C)");
    write_line("Exit Program (X)");
    write("Enter your choice: ");
}

void display_category_menu(Category &category) {
    clear_console();
    write_line("=== Category: " + category.name + " ===");
    write_line("---------------------------------------------");
    write_line("| Item No. | Name      | Stock Status      |");
    write_line("|----------|-----------|-------------------|");

    if (category.items.empty()) {
        write_line("|          (No items in category)         |");
    } else {
        for (int i = 0; i < category.items.size(); ++i) {
            Item &item = category.items[i];
            auto status = get_stock_status(item.quantity, item.capacity);
            std::string status_str = std::to_string(item.quantity) + "/" + std::to_string(item.capacity) + " " + status.second;

            std::string line = "| ";
            line += std::to_string(i + 1);
            line += std::string(9 - std::to_string(i + 1).length(), ' '); // Use std::string for constructor
            line += "| ";
            line += item.name;
            line += std::string(10 - item.name.length(), ' '); // Use std::string for constructor
            line += "| ";
            line += status.first;
            line += status_str;
            line += std::string(18 - status_str.length(), ' '); // Use std::string for constructor
            line += MY_COLOR_RESET;
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