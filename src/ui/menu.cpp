#include "../../include/ui/menu.hpp"

Menu::Menu(const std::string &title, const std::vector<MenuOption> &options)
    : title(title), options(options) {}

void Menu::display() const
{
    while (true)
    {

        cout << BLUE << "----------------------------------------------\n"
             << "================= " << title << " ==================\n"
             << "----------------------------------------------\n" << RESET;


        for (size_t i = 0; i < options.size(); ++i)
        {
            cout << i + 1 << ". " << setw(15) << left << options[i].label
                 << " - " << options[i].description
                 << "\n";
        }

        cout << "> ";

        int choice;
        if (cin >> choice)
        {
            if (choice >= 1 && choice <= (int)options.size())
            {
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
