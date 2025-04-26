#ifndef CATEGORY_ACTIONS_H
#define CATEGORY_ACTIONS_H

#include "models.h" // For Category type (used in function parameters)
                    // models.h also brings in <string> and <vector> if needed.
// Removed utils.h and direct string includes if not needed by declarations.

void add_new_category();
void add_item_to_category(Category &category);
void remove_item_from_category(Category &category);
void change_item_quantity(Category &category);
void change_item_capacity(Category &category);

#endif // CATEGORY_ACTIONS_H

