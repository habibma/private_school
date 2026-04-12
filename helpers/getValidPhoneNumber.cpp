#include "../include/private_school.hpp"

string	getValidPhoneNumber(const string &prompt)
{
    string	phoneNumber;
    while (true) {
        cout << prompt << endl
             << "> ";
        getline(cin, phoneNumber);
        if (isOnlyDigits(phoneNumber)) {
            return (phoneNumber);
        } else {
            cout << "Invalid input. Only digits are allowed.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
