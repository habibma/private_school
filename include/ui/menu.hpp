#ifndef MENU_HPP
#define MENU_HPP

#include "../private_school.hpp"
#include <iomanip>
#include <functional>

struct MenuOption {
	string label;
	string description;
    std::function<void()> action;
};

class Menu {
    public:
        Menu(const std::string& title, const std::vector<MenuOption>& options)
            : title(title), options(options) {}

        void display() const {
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
                        options[choice - 1].action();
                        return;
                    }
                }

                cout << "Invalid choice. Try again. Please use the number corresponding to your choice.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

    private:
        std::string title;
        std::vector<MenuOption> options;
};

#endif