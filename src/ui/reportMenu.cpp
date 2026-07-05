#include "../include/ui/reportMenu.hpp"
#include "../include/MessageManager.hpp"
#include "../include/Reports.hpp"
#include "../include/ui/Menu.hpp"
#include "../include/utils/Terminal.hpp"

void showReportMenu(const School &school)
{
	if (school.getName().empty())
	{
		MessageManager::warning("No school data available. Please set up your school first.");
		return;
	}

	bool shouldExit = false;

	Menu reportMenu("SCHOOL REPORT", {{"SCHOOL SUMMARY", "View a summary of the school", [&school]()
									   { Reports::schoolSummary(school); utils::pauseForInput(); }},
									  {"CLASSROOMS", "View a list of classrooms in the school", [&school]()
									   { Reports::classrooms(school); utils::pauseForInput(); }},
									  {"STUDENTS", "View a list of students in the school", [&school]()
									   { Reports::students(school); utils::pauseForInput(); }},
									  {"STATISTICS", "View various statistics about the school", [&school]()
									   { Reports::statistics(school); utils::pauseForInput(); }},
									  {"BACK TO MAIN MENU", "Return to the main menu", [&shouldExit]()
									   { shouldExit = true; }}});

	while (!shouldExit)
	{
		reportMenu.display();
	}
}
