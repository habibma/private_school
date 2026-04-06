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

		void setSubject(const string &subject);
		string getSubject() const;

		void addStudent(const Student &s);
		vector<Student> getStudents() const;

};

#endif