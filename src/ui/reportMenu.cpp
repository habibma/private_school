#include "../include/ui/reportMenu.hpp"
#include "../include/MessageManager.hpp"
#include "../include/Reports.hpp"
#include "../include/ui/Menu.hpp"

void reportMenu(const School &school)
{
	if (school.getName().empty())
	{
		MessageManager::warning("No school data available. Please set up your school first.");
		return;
	}

	Menu reportMenu("SCHOOL REPORT", {
		{"SCHOOL SUMMARY", "View a summary of the school", [&school]() { Reports::schoolSummary(school); }},
		{"CLASSROOMS", "View a list of classrooms in the school", [&school]() { Reports::classrooms(school); }},
		{"STUDENTS", "View a list of students in the school", [&school]() { Reports::students(school); }},
		{"STATISTICS", "View various statistics about the school", [&school]() { Reports::statistics(school); }},
		{"BACK TO MAIN MENU", "Return to the main menu", []() {}}
	});

	reportMenu.display();

}