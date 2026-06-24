#ifndef PRIVATE_TEACHER_H
# define PRIVATE_TEACHER_H

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"
# define BOLD    "\033[1m"
# define SMALL   "\033[2m"
# define UNDERLINE "\033[4m"
# define REVERSE "\033[7m"
# define MAGENTA "\033[35m"

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
# include <fstream>
using namespace std;


// Function declaration
bool    isOnlyLetters(const string &s);
bool    isOnlyDigits(const string &s);
bool    fileExists(const std::string &filename);

// helper functions
string	getValidName(const string &prompt);
int		getValidNumber(const string &prompt);
string	getValidPhoneNumber(const string &prompt);
string  getValidEmail(const string &prompt);

#endif
