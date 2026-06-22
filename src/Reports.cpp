#include "../include/Reports.hpp"

void Reports::schoolSummary(const School& school)
{
	// Implement the logic to display a summary of the school
	std::cout << "School Name: " << school.getName() << std::endl;
	std::cout << "Number of Classrooms: " << school.getClassrooms().size() << std::endl;
	std::cout << "Number of Students: " << school.getStudents().size() << std::endl;
}

void Reports::classrooms(const School& school)
{
	// Implement the logic to display a list of classrooms in the school
	std::cout << "Classrooms in " << school.getName() << ":\n";
	for (const auto& classroom : school.getClassrooms())
	{
		//std::cout << "- " << classroom.getSubject() << " (Teacher: " << classroom.getTeacher().getName() << ")\n";
		std::cout << "- " << classroom.getSubject() << "\n";
	}
}

void Reports::students(const School& school)
{
	// Implement the logic to display a list of students in the school
	std::cout << "Students in " << school.getName() << ":\n";
	for (const auto& student : school.getStudents())
	{
		std::cout << "- " << student.getName() << " (Grade: " << student.getGrade() << ")\n";
	}
}

void Reports::statistics(const School& school)
{
	// Implement the logic to display various statistics about the school
	std::cout << "Statistics for " << school.getName() << ":\n";
	std::cout << "Average Grade: " << school.getAverageGrade() << std::endl;
	std::cout << "Highest Grade: " << school.getHighestGrade() << std::endl;
	std::cout << "Lowest Grade: " << school.getLowestGrade() << std::endl;
}
