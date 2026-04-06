#ifndef PRIVATE_TEACHER_H
# define PRIVATE_TEACHER_H

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
using namespace std;

// Function declaration
bool isOnlyLetters(const string &s);

// helper functions
string	getValidName(const string &prompt);
int		getValidNumber(const string &prompt);

#endif
