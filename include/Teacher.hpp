#ifndef TEACHER_HPP
# define TEACHER_HPP

#include "private_teacher.hpp"
#include "Classroom.hpp"
#include "Student.hpp"

class Teacher
{
	private:
		string			firstName;
		string			lastName;
		vector<Classroom>	classrooms;

	public:
		Teacher();
		~Teacher();
		Teacher(const Teacher &other);
		Teacher &operator=(const Teacher &other);
		Teacher(const string &firstName, const string &lastName);

		void setFirstName(const string &firstName);
		void setLastName(const string &lastName);

		void addClassroom(const Classroom &classroom);
		void addStudentToClassroom(const Student &s, unsigned int classroomIndex);

		string getFirstName() const;
		string getLastName() const;
		vector<Classroom> getClassrooms() const;
};

#endif