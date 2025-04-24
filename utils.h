
#ifndef UTILS_H
#define UTILS_H
#include <string> 

void clear_console();
int read_integer(const std::string &prompt);
int read_integer_range(const std::string &prompt, int min_val, int max_val);

#endif // UTILS_H
