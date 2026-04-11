#include "include/private_school.hpp"
#include "include/Teacher.hpp"
#include "include/School.hpp"
#include "include/ui/buildSchool.hpp"


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
	cout << BOLD << "=== WELCOME TO THE SCHOOL MANAGEMENT SYSTEM ===\n" << RESET;
	string schoolName = getValidName("Write the name of your school: ");
	School school(schoolName);

	while (1)
	{
		cout << BOLD << "\n=== MAIN MENU ===\n"
				  << RESET;
		cout << "1. " << GREEN << "START" << RESET << "  - Build a school\n";
		cout << "2. " << CYAN << "REPORT" << RESET << " - Show statistics\n";
		cout << "3. " << RED << "EXIT" << RESET << "   - Exit program\n";
		cout << BOLD << "Choose an option \n" << RESET;
		cout << "> ";
		string prompt;
		getline(cin, prompt);
		if (prompt == "START")
		{
			buildSchool(school);
		}
		else if (prompt == "REPORT")
		{
			if (school.getTeachers().empty())
			{
				cout << "No teachers in the school. Please add a teacher first." << endl;
				continue;
			}
			printReport(school);
		}
		else if (prompt == "EXIT")
		{
			return 0;
		}
		else
			cout << RED << "Invalid input. Please enter 'START', 'REPORT', or 'EXIT'." << endl
				 << RESET;
	}
	return (0);
}