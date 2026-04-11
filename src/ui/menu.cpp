#include "../../include/ui/menu.hpp"

int showMenu(const string& title,
             const vector<MenuOption>& options)
{
    while (true) {
        cout << "\n=== " << title << " ===\n";

        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << setw(10) << left << options[i].label
            << " - " << options[i].description
            << "\n";
        }

        cout << "> ";

        int choice;
        if (cin >> choice) {
            if (choice >= 1 && choice <= (int)options.size()) {
                cin.ignore(1000, '\n');
                return choice;
            }
        }

        cout << "Invalid choice. Try again. Please use the number corresponding to your choice.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return -1; // This line will never be reached, but it prevents a compiler warning.
}