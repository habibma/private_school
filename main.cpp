#include "include/private_school.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"
#include "include/ui/menu.hpp"

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
	// To start the program:
	// 1- what is the name the school?
	// TODO:
	// 2- the admin should be able to add classrooms to the school
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

	// for the first time the program runs, the school will be empty and the admin will have to add classrooms and students to the school before being able to print any reports. The main menu will have an option to setup the school, which will allow the admin to add classrooms and students to the school. Once the school is set up, the admin can choose to print reports or exit the program.	
	if (true)
	{
		cout << YELLOW << "It looks like this is your first time running the program. Let's set up your school!" << RESET << endl;
	}
	string schoolName = getValidName("Write the name of your school: ");
	School school(schoolName);

	// options for the main menu
	std::vector<MenuOption> mainMenu = {
		{"SETUP SCHOOL", "Configure your school", [&school]() mutable { buildSchool(school); }},
		{"VIEW REPORT", "View the school report", [&school]() { printReport(school); }},
		{"EXIT", "Exit", []() { exit(0); }}};

	Menu menu("MAIN MENU", mainMenu);

	while (true)
	{
		menu.display();
	}
	return (0);
}