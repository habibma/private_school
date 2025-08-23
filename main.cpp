#include "private_teacher.hpp"

string	getValidName(const string &prompt)
{
	string	name;
	while (true) {
		cout << prompt;
		getline(cin, name);
		if (isOnlyLetters(name)) {
			return (name);
		} else {
			cout << "Invalid input. Only letters are allowed.\n";
		}
	}
}

int	getValidNumber(const string &prompt)
{
	int	num;
	while (true)
	{
		cout << prompt;
		if (cin >> num)
			return (num);
		else
		{
			cout << "Invalid input! Please enter a number.\n";
			cin.clear();
            cin.ignore(1000, '\n');
		}
	}
}

int	main(void)
{
	// defining a teacher
	teacher teacher1;

	// to catch the teacher's info
	teacher1.firstName		= getValidName("Write your first name: ");
	teacher1.lastName		= getValidName("Write your Last name: ");
	teacher1.subject		= getValidName("Subject: ");
	// to catch the quantity of students of the class
	int		student_numbers	= getValidNumber("How many students you have? ");

	// to save the calculation of sum of scores
	double	sum	 = 0;

	// to ignore arbitarily numbers of leftover "\n" in the cin buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// to make the vector filling optimized
	teacher1.students.reserve(student_numbers);

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
		teacher1.students.push_back(s);
	}
	// To print the class report
	cout << "\nTeacher: " << teacher1.firstName << " " << teacher1.lastName
		<< " (" << teacher1.subject << ")\n";
	cout << "Students:\n";
    for (const student& student : teacher1.students) {
        std::cout << " - " << student.name << " : " << student.score << "\n";
    }
	for (const student &student : teacher1.students)
		sum += student.score;
	cout << "The Average of Your Class is : " << sum / student_numbers << endl;
	return (0);
}