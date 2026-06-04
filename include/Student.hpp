#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <string>

class Student
{
	private:
		std::string _name;
		double _score;
		Student();

	public:
		Student(std::string name);
		Student(std::string name, double score);
		Student(const Student &other);
		Student &operator=(const Student &other);
		~Student();

		//getters
		std::string getName() const;
		double getScore() const;

};

#endif