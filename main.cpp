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
