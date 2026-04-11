#include "../include/private_school.hpp"

int	getValidNumber(const string &prompt)
{
	int	num;

	while (true)
	{
		cout << prompt;
		if (cin >> num)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return (num);
		}
		else
		{
			cout << RED << "Invalid input! Please enter a number.\n" << RESET;
			cin.clear();
            cin.ignore(1000, '\n');
		}
	}
}