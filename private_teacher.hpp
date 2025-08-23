#ifndef PRIVATE_TEACHER_H
# define PRIVATE_TEACHER_H

# include <string>
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
using namespace std;

struct student
{
	string	name;
	int		score;
};

struct teacher
{
	string			firstName;
	string			lastName;
	string			subject;
	vector<student>	students;
};

// Function declaration
bool isOnlyLetters(const string &s);

#endif
