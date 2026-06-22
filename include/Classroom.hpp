#ifndef CLASS_HPP
# define CLASS_HPP

#include <string>
#include <vector>
using namespace std;

#include "Student.hpp"

class Classroom
{
	private:
		string _subject;
		vector<Student> students;

	public:
		Classroom();
		Classroom(string subject);
		~Classroom();

		string getSubject() const;
		vector<Student> getStudents() const;

		void setSubject(const string &subject);

		void addStudent(const Student &s);
		double getAverageGrade() const;

};

#endif