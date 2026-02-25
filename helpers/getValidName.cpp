#include "../include/private_teacher.hpp"

string	getValidName(const string &prompt)
{
	string	name;
	while (true) {
		cout << prompt;
		getline(cin, name);
		if (isOnlyLetters(name)) {
			return (name);
		} else {
			cout << "Invalid input. Only letters are allowed.\n";
		}
	}
}