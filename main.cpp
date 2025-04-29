#include "splashkit.h"
#include "models.h"  // Include data model definitions
#include "utils.h"   // Include utility functions
#include "status.h"  // Include status definitions
#include "display.h" // Include display functions
#include "category_actions.h" // Include category actions

// Global definition of the categories vector
std::vector<Category> categories; 

// Function to handle the category-specific menu and actions
void view_category(int category_index) {
    Category &selected_category = categories[category_index]; // Uses the global 'categories'

    while (true) {
        display_category_menu(selected_category); // From display.h
        std::string choice_str = read_line();     // From splashkit.h
        char choice = (choice_str.length() == 1) ? toupper(choice_str[0]) : ' ';

        switch (choice) {
            case 'Q':
                change_item_quantity(selected_category); // From category_actions.h
                write_line("\nPress Enter to continue..."); read_line();
                break;
            case 'C':
                change_item_capacity(selected_category); // From category_actions.h
                write_line("\nPress Enter to continue..."); read_line();
                break;
            case 'A':
                add_item_to_category(selected_category); // From category_actions.h
                write_line("\nPress Enter to continue..."); read_line();
                break;
            case 'R':
                remove_item_from_category(selected_category); // From category_actions.h
                write_line("\nPress Enter to continue..."); read_line();
                break;
            case 'X':
                return; // Go back to the main menu
            default:
                write_line("Invalid choice. Please try again.");
                delay(1000); // From splashkit.h
                break;
        }
    }
};

// Main function to run the inventory management system

int main() {
    clear_console();
    bool running = true;
    while (running) {
        display_main_menu(); // From display.h
        std::string input_line = read_line();

        if (input_line.length() == 1) {
            char char_choice = toupper(input_line[0]);
            if (input_line == "C") {
                add_new_category();
                continue; // From category_actions.h
            } else if (input_line == "X") {
                running = false;
                continue;
            }
        }

        // Try to convert to integer for category selection
        if (is_integer(input_line)) { // 
            int choice_num = convert_to_integer(input_line); 
            if (choice_num >= 1 && choice_num <= categories.size()) {
                view_category(choice_num - 1); // Call our view_category function
            } else {
                // Handles numbers out of valid category range
                write_line("Invalid category number. Please try again.");
                delay(1000); 
            }
        } else {
            // Handles input that isn't 'C', 'X', or a valid integer choice
            // This condition ensures I don't double-print "Invalid choice"
            // if it was a single char that wasn't 'C' or 'X'.
            if (!(input_line.length() == 1 && (toupper(input_line[0]) == 'C' || toupper(input_line[0]) == 'X'))) {
                 write_line("Invalid choice. Please try again.");
                 delay(1000);
            }
        }
    }

    clear_console(); // From utils.h
    write_line("Exiting Inventory Tracking System. Goodbye!");

    return 0;
}