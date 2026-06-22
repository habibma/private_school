#include "include/private_school.hpp"
#include "include/SchoolManager.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"
#include "include/ui/Menu.hpp"
#include "include/ui/reportMenu.hpp"
#include "include/setupWizard.hpp"
#include "include/MessageManager.hpp"

int main(void)
{
	SchoolManager manager;

	// Welcome message
	MessageManager::info("=== WELCOME TO THE SCHOOL MANAGEMENT SYSTEM ===");

	// for the first time the program runs,
	// it will run the setup wizard to create a new school,
	// otherwise, it will load the existing school data from the file

	School mainSchool =
		manager.schoolExists()
		? manager.load()
		: runSetupWizard(manager);


	// options for the main menu
	std::vector<MenuOption> mainMenu = {
		{"MANAGE SCHOOL", "Configure your school", [&mainSchool, &manager]() { buildSchool(mainSchool, manager); }},
		{"VIEW REPORT", "View the school report", [&mainSchool]() { reportMenu(mainSchool); }},
		{"EXIT", "Exit", []() { exit(0); }}};

	Menu menu("MAIN MENU", mainMenu);

	while (true)
	{
		menu.display();
	}
	return (0);
}
