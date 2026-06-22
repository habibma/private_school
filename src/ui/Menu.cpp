#include "../../include/ui/Menu.hpp"
#include "../../include/MessageManager.hpp"
#include "../../include/utils/TerminalUtils.hpp"

std::vector<std::string> Menu::_breadcrumbs;

Menu::Menu(const std::string &title, const std::vector<MenuOption> &options)
    : title(title), options(options)
{
    addbreadcrumbs(title);
}

Menu::~Menu()
{
    removebreadcrumbs();
}


void Menu::display() const
{

    utils::clearScreen();

    cout << BLUE << "----------------------------------------------\n"
         << "================= " << BOLD << title << RESET << BLUE << " ==================\n"
         << "----------------------------------------------\n"
         << RESET;

    printBreadcrumbs();

    cout << BLUE << "----------------------------------------------\n"
         << RESET;

    for (size_t i = 0; i < options.size(); ++i)
    {
        cout << i + 1 << ". " << setw(20) << left << options[i].label
             << " - " << options[i].description
             << "\n";
    }

    MessageManager::prompt("Enter your choice: ");
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

    MessageManager::error("Invalid choice. Try again. Please use the number corresponding to your choice.");
    cin.clear();
    cin.ignore(1000, '\n');
}

// TODO: to add menu manager that will handle the breadcrumbs and the navigation between menus, and to add a way to go back to the previous menu
// for now, the breadcrumbs will be handled manually by the caller of the menu, but in the future, it will be handled by the menu manager that will be responsible for navigating between menus and handling the breadcrumbs automatically

void Menu::addbreadcrumbs(const std::string &path)
{
    _breadcrumbs.push_back(path);
}

void Menu::removebreadcrumbs()
{
    if (!_breadcrumbs.empty())
        _breadcrumbs.pop_back();
}

void Menu::printBreadcrumbs() const
{
    if (!_breadcrumbs.empty())
    {
        for (size_t i = 0; i < _breadcrumbs.size(); ++i)
        {
            cout << REVERSE << " " << _breadcrumbs[i] << " > " << RESET << " ";
        }
        cout << "\n";
    }
}
