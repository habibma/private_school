#include "include/private_school.hpp"
#include "include/SchoolManager.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"
#include "include/ui/menu.hpp"
#include "include/setupWizard.hpp"
#include "include/MessageManager.hpp"

void printReport(const School &school)
{
	if (school.getClassrooms().empty())
	{
		MessageManager::warning("No classrooms in the school yet. Please add classrooms to see the report.");
		return;
	}

	MessageManager::info("School Name: " + school.getName());
	for (const auto &classroom : school.getClassrooms())
	{
		MessageManager::info("Classroom Subject: " + classroom.getSubject());
		if (classroom.getStudents().empty())
		{
			MessageManager::warning("No students in this classroom yet.");
			continue;
		}
		double totalScore = 0;
		for (const auto &student : classroom.getStudents())
		{
			MessageManager::info("  Student Name: " + student.getName() + ", Score: " + std::to_string(student.getScore()));
			totalScore += student.getScore();
		}
		double averageScore = totalScore / classroom.getStudents().size();
		MessageManager::info("  Average Score: " + std::to_string(averageScore));
	}
}

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
		{"VIEW REPORT", "View the school report", [&mainSchool]() { printReport(mainSchool); }},
		{"EXIT", "Exit", []() { exit(0); }}};

	Menu menu("MAIN MENU", mainMenu);

	while (true)
	{
		menu.display();
	}
	return (0);
}
