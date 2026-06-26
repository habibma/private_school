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
		string _material; // Assuming you want to store a single material for simplicity. TODO: change this to a Material class.

	public:
		Classroom();
		Classroom(string subject);
		~Classroom();

		string getSubject() const;
		vector<Student> getStudents() const;

		void setSubject(const string &subject);

		void addStudent(const Student &s);
		double getAverageGrade() const;

		void addMaterial(const string &material);

		void removeClassroomFromSchool(vector<Classroom> &classrooms);

};

#endif