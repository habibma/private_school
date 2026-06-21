#include "../../include/ui/menu.hpp"

std::vector<std::string> Menu::_breadcrumbs;

Menu::Menu(const std::string &title, const std::vector<MenuOption> &options)
    : title(title), options(options)
    {
        _breadcrumbs.push_back(title);
    }

Menu::~Menu() {
    _breadcrumbs.pop_back();
}

void Menu::display() const
{
    while (true)
    {

        cout << BLUE << "----------------------------------------------\n"
             << "================= " << BOLD << title << RESET << BLUE <<" ==================\n" << RESET;

        printBreadcrumbs();

        cout << BLUE << "----------------------------------------------\n" << RESET;

        for (size_t i = 0; i < options.size(); ++i)
        {
            cout << i + 1 << ". " << setw(20) << left << options[i].label
                 << " - " << options[i].description
                 << "\n";
        }

        cout << "\nPlease choose an option:\n";
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

// TODO: to add menu manager that will handle the breadcrumbs and the navigation between menus, and to add a way to go back to the previous menu
// for now, the breadcrumbs will be handled manually by the caller of the menu, but in the future, it will be handled by the menu manager that will be responsible for navigating between menus and handling the breadcrumbs automatically
void Menu::printBreadcrumbs() const
{
    if (!_breadcrumbs.empty())
    {
        cout << SMALL << "You are here: " ;
        for (size_t i = 0; i < _breadcrumbs.size(); ++i)
        {
            cout << _breadcrumbs[i];
            if (i < _breadcrumbs.size() - 1)
                cout << " > ";
        }
        cout << "\n" << RESET;
    }
}
