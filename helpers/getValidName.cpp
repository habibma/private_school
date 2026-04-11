#include "../include/private_school.hpp"

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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}