#ifndef MENU_HPP
#define MENU_HPP

#include "../private_school.hpp"


struct MenuOption {
	string label;
	string description;
};

int showMenu(const std::string& title,
             const std::vector<MenuOption>& options);

#endif