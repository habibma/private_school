#ifndef PRIVATE_TEACHER_H
# define PRIVATE_TEACHER_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
using namespace std;


// Function declaration
bool    isOnlyLetters(const string &s);

// helper functions
string	getValidName(const string &prompt);
int		getValidNumber(const string &prompt);

#endif
