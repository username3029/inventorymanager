#include "splashkit.h"
#include "models.h"  // Include data model definitions
#include "utils.h"   // Include utility functions
#include "status.h"  // Include status definitions

int main() {
    clear_console();

    // Test status logic (demo line)
    auto status = get_stock_status(4, 10);
    write_line("Stock Status: " + status.first + status.second + MY_COLOR_RESET);

    return 0;
}


