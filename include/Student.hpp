#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <string>
using namespace std;

class Student
{
	private:
		string _name;
		double _score;
		Student();

	public:
		Student(string name, double score);
		~Student();

		//getters
		string getName() const;
		double getScore() const;
};

#endif