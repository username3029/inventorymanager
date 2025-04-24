#ifndef UTILS_H
#define UTILS_H

#include "splashkit.h"
#include "utils.h"
#include <string>


// Clears the terminal/console screen based on operating system
void clear_console() {
    #ifdef _WIN32
        system("cls");  // For Windows systems
    #else
        system("clear");  // For macOS/Linux systems
    #endif
}

// Prompts the user to enter a whole number (integer) and validates the input
int read_integer(const std::string &prompt) {
    write(prompt);  // Display the prompt
    std::string line = read_line();  // Read user input

    // Loop until the user inputs a valid integer
    while (!is_integer(line)) {
        write_line("Invalid input. Please enter a whole number.");
        write(prompt);
        line = read_line();
    }

    return convert_to_integer(line);  // Convert valid input to int
}

// Prompts for a number within a specific range [min_val, max_val]
int read_integer_range(const std::string &prompt, int min_val, int max_val) {
    int value = read_integer(prompt);  // Reuse earlier function

    // Validate range
    while (value < min_val || value > max_val) {
        write_line("Input out of range. Please enter a number between "
                    + std::to_string(min_val) + " and " + std::to_string(max_val) + ".");
        value = read_integer(prompt);
    }

    return value;
}

#endif // UTILS_H
