#ifndef STATUS_H
#define STATUS_H

#include <string> // For std::string and std::pair
#include <utility> // For std::pair

// ANSI colour escape codes for coloured console output
const std::string MY_COLOR_RESET  = "\033[0m";
const std::string MY_COLOR_RED    = "\033[31m";
const std::string MY_COLOR_YELLOW = "\033[33m";
const std::string MY_COLOR_GREEN  = "\033[32m";

// Function declaration
std::pair<std::string, std::string> get_stock_status(int quantity, int capacity);

#endif // STATUS_H