#include "../include/private_school.hpp"

string	getValidName(const string &prompt)
{
	string	name;
	while (true) {
		cout << "\n" << BLUE << prompt << RESET << endl
			 << "> ";
		getline(cin, name);
		if (isOnlyLetters(name)) {
			return (name);
		} else {
			cout << RED << "Invalid input. Only letters are allowed. Press Enter to continue..." << RESET << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
