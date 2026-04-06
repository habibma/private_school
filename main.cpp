#include "include/private_teacher.hpp"
#include "include/Teacher.hpp"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

int	main(void)
{
	// To start the program, we will first ask the teacher to fill in his/her information
	// Then if they wants to to add a class
	// Then the class should be the students' information,
	// Then we will print a report of the class with the average score of the students.
	// Defining a teacher
	

	// to catch the teacher's information
	string	firstName		= getValidName("Write your first name: ");
	string	lastName		= getValidName("Write your Last name: ");
	
	// to build the teacher object with the information just caught
	Teacher *teacher1;
	
	teacher1 = new Teacher(firstName, lastName);
	
	while (1)
	{
		string	prompt;
		cout << "ADD to add a class, START to start the program, or EXIT to exit the program: ";
		getline(cin, prompt);
		if (prompt == "ADD")
		{
			string subject = getValidName("What is the subject of your class? ");
			Classroom	classroom(subject);
			teacher1->addClassroom(classroom);

			while (1)
			{
				string studentName = getValidName("What is the name of the student? (or type 'DONE' to finish adding students) ");
				if (studentName == "DONE")
					break ;
				int score = getValidNumber("What is the score of the student? ");
				try {
					Student student(studentName, score);
					teacher1->addStudentToClassroom(student, teacher1->getClassrooms().size() - 1);
					cout << GREEN << "Student added successfully!" << endl << RESET;
				}
				catch (const std::exception &e) {
					cout << RED << "Error: " << e.what() << "Trying again..." << endl << RESET;
				}
			}
		}
		else if (prompt == "START")
		{
			if (teacher1->getClassrooms().empty())
			{
				cout << "You don't have any class. Please add a class first." << endl;
				continue ;
			}
			for (size_t i = 0; i < teacher1->getClassrooms().size(); i++)
			{
				cout << "Class " << i + 1 << ": " << teacher1->getClassrooms()[i].getSubject() << endl;
				vector<Student> students = teacher1->getClassrooms()[i].getStudents();
				if (students.empty())
				{
					cout << "No students in this class." << endl;
					continue ;
				}
				double totalScore = 0.0;
				for (size_t j = 0; j < students.size(); j++)
				{
					cout << "Student " << j + 1 << ": " << students[j].getName() << ", Score: " << students[j].getScore() << endl;
					totalScore += students[j].getScore();
				}
				double averageScore = totalScore / students.size();
				cout << "Average Score: " << averageScore << endl;
			}
			break ;
		}
		else if (prompt == "EXIT")
		{
			break ;
		}
		else
			cout << "Invalid input. Please enter 'ADD' or 'START'." << endl;
	}
	

	delete teacher1;
	return (0);
}