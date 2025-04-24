#include <string>
using std::string;

// ANSI colour escape codes for coloured console output
const string MY_COLOR_RESET  = "\033[0m";  // Reset to default
const string MY_COLOR_RED    = "\033[31m"; // Red color (low stock)
const string MY_COLOR_YELLOW = "\033[33m"; // Yellow color (medium stock)
const string MY_COLOR_GREEN  = "\033[32m"; // Green color (high stock)

std::pair<string, string> get_stock_status(int quantity, int capacity) {
    // Invalid capacity check
    if (capacity <= 0) {
        return {MY_COLOR_RED, "(Invalid Capacity)"};
    }

    // Calculate fill percentage
    double percentage = static_cast<double>(quantity) / capacity * 100.0;

    // Determine status based on fill percentage
    if (percentage < 30.0) {
        return {MY_COLOR_RED, "(Low)"};
    } else if (percentage < 70.0) {
        return {MY_COLOR_YELLOW, "(Medium)"};
    } else {
        return {MY_COLOR_GREEN, "(High)"};
    }
}