#include "include/private_school.hpp"
#include "include/SchoolManager.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"
#include "include/ui/menu.hpp"
#include "include/setupWizard.hpp"

void printReport(const School &school)
{
	if (school.getClassrooms().empty())
	{
		cout << YELLOW << "No classrooms in the school yet. Please add classrooms to see the report." << RESET << endl;
		return;
	}

	cout << "School Name: " << school.getName() << std::endl;
	for (const auto &classroom : school.getClassrooms())
	{
		cout << "Classroom Subject: " << classroom.getSubject() << std::endl;
		if (classroom.getStudents().empty())
		{
			cout << YELLOW << "No students in this classroom yet." << RESET << endl;
			continue;
		}
		double totalScore = 0;
		for (const auto &student : classroom.getStudents())
		{
			cout << "  Student Name: " << student.getName() << ", Score: " << student.getScore() << std::endl;
			totalScore += student.getScore();
		}
		double averageScore = totalScore / classroom.getStudents().size();
		cout << "  Average Score: " << averageScore << std::endl;
	}
}

int main(void)
{
	SchoolManager manager;

	// Wlcomme message
	cout << BOLD << "=== WELCOME TO THE SCHOOL MANAGEMENT SYSTEM ===\n"
		 << RESET;

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
		{"VIEW REPORT", "View the school report", [&mainSchool]() { printReport(mainSchool); }},
		{"EXIT", "Exit", []() { exit(0); }}};

	Menu menu("MAIN MENU", mainMenu);

	while (true)
	{
		menu.display();
	}
	return (0);
}
