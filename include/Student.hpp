#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <string>

class Student
{
	private:
		std::string _name;
		double		_grade;
		Student();

	public:
		Student(std::string name);
		Student(std::string name, double grade);
		Student(const Student &other);
		Student &operator=(const Student &other);
		~Student();

		//getters
		std::string	getName() const;
		double		getGrade() const;

};

#endif