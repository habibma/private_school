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
        Menu(const std::string& title, const std::vector<MenuOption>& options);
        void    display() const;

    private:
        std::string title;
        std::vector<MenuOption> options;
};

#endif