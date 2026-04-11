#include "include/private_school.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"
#include "include/ui/menu.hpp"

void printReport(const School &school)
{
	cout << "School Name: " << school.getName() << std::endl;
	for (const auto &teacher : school.getTeachers())
	{
		cout << "Teacher: " << teacher.getFirstName() << " " << teacher.getLastName() << std::endl;
		for (const auto &classroom : teacher.getClassrooms())
		{
			cout << "  Classroom: " << classroom.getSubject() << std::endl;
			cout << "    Average Score: " << classroom.getAverageScore() << std::endl;
		}
	}
}

int main(void)
{
	// To start the program:
	// 1- what is the name the school?
	// TODO:
	// 2- the admin should be able to add teachers to the school, and each teacher should be able to add classes to their profile.
	// 3- each class should have a subject and a list of students with their scores.
	// 4- the admin should be able to print a report of each class with the average score of the students.
	// 5- the admin should be able to print a report of each teacher with the classes they teach and the average score of the students in each class.
	// 6- the admin should be able to print a report of the school with the teachers and their classes and the average score of the students in each class.
	// 7- the admin should be able to exit the program.
	// 8- the program should be able to handle invalid input and display appropriate error messages.
	// 9- the program should be able to handle memory management and avoid memory leaks.
	// 10- the program should be able to handle exceptions and display appropriate error messages.
	// 11- the program should be able to handle edge cases and display appropriate error messages.

	// to catch the school's information
	cout << BOLD << "=== WELCOME TO THE SCHOOL MANAGEMENT SYSTEM ===\n"
		 << RESET;
	string schoolName = getValidName("Write the name of your school: ");
	School school(schoolName);

	// options for the main menu
	std::vector<MenuOption> mainMenu = {
		{"START", "Start building your school"},
		{"REPORT", "Show report"},
		{"EXIT", "Exit"}};

	while (1)
	{
		int choice = showMenu("MAIN MENU", mainMenu);
		switch (choice)
		{
			case 1:
				buildSchool(school);
				break;
			case 2:
				if (school.getTeachers().empty())
				{
					cout << RED << "No teachers in the school. Please add a teacher first." << endl
						 << RESET;
					continue;
				}
				printReport(school);
				break;
			case 3:
				return 0;
			default:
				cout << RED << "Invalid input. Please enter 'START', 'REPORT', or 'EXIT'." << endl
					 << RESET;
		}
	}
	return (0);
}