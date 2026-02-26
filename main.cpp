#include "include/private_teacher.hpp"
#include "include/Teacher.hpp"

int	main(void)
{
	// To start the program, we will first ask the teacher to fill in his/her information and the students' information,
	//then we will print a report of the class with the average score of the students.
	// defining a teacher

	// to catch the teacher's information
	string	firstName		= getValidName("Write your first name: ");
	string	lastName		= getValidName("Write your Last name: ");
	string	subject		= getValidName("Subject: ");

	// to build the teacher object with the information just caught
	Teacher teacher1(firstName, lastName, subject);

	// to catch the quantity of students of the class
	int		student_numbers	= getValidNumber("How many students you have? ");

	// to save the calculation of sum of scores
	double	sum	 = 0;

	// to ignore arbitarily numbers of leftover "\n" in the cin buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// the process of populating the vector students from user inputs
	for (int i = 1; i <= student_numbers; i++)
	{
		// declaring a new object (the struct is already defined in the header file. check the minishell.hpp)
		student	s;
		// to catch the name of student number i
		s.name	= getValidName("The name of student " + to_string(i) + ": ");
		// to catch the score of student number i
		s.score	= getValidNumber("The score of student " + to_string(i) + ": ");
		//to ignore next_line character for the second
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// to add the struct just built now the tail of the students vector
		teacher1.addStudent(s);
	}

	// To print the class report
	cout << "\nTeacher: " << teacher1.getFirstName() << " " << teacher1.getLastName()
		<< " (" << teacher1.getSubject() << ")\n";
	cout << "Students:\n";
    for (const student& student : teacher1.getStudents()) {
        std::cout << " - " << student.name << " : " << student.score << "\n";
    }
	for (const student &student : teacher1.getStudents())
		sum += student.score;
	cout << "The Average of Your Class is : " << sum / student_numbers << endl;
	return (0);
}