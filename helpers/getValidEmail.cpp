#include "../include/private_school.hpp"

string  getValidEmail(const string &prompt)
{
    string  email;
    while (true) {
        cout << prompt << endl
             << "> ";
        getline(cin, email);
        if (email.empty()) {
            return (email);
        }
        if (email.find('@') != string::npos && email.find('.') != string::npos) {
            return (email);
        } else {
            cout << "Invalid input. Please enter a valid email address.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
