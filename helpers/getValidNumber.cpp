#include "../include/private_teacher.hpp"

int	getValidNumber(const string &prompt)
{
	int	num;

	while (true)
	{
		cout << prompt;
		if (cin >> num)
			return (num);
		else
		{
			cout << "Invalid input! Please enter a number.\n";
			cin.clear();
            cin.ignore(1000, '\n');
		}
	}
}