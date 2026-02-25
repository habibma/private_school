#ifndef TEACHER_HPP
# define TEACHER_HPP

#include "private_teacher.hpp"

class Teacher
{
	private:
		string			firstName;
		string			lastName;
		string			subject;
		vector<student>	students;

	public:
		Teacher();
		~Teacher();
		Teacher(const Teacher &other);
		Teacher &operator=(const Teacher &other);
		Teacher(const string &firstName, const string &lastName, const string &subject);

		void setFirstName(const string &firstName);
		void setLastName(const string &lastName);
		void setSubject(const string &subject);

		void addStudent(const student &s);

		string getFirstName() const;
		string getLastName() const;
		string getSubject() const;
		vector<student> getStudents() const;
};

#endif