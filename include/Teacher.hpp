#ifndef TEACHER_HPP
# define TEACHER_HPP

#include "Classroom.hpp"
#include "Student.hpp"

// todo later: make phone number a string to handle different formats and country codes
struct Demographics
{
	string	firstName;
	string	lastName;
	int		age;
	string	phoneNumber;
	string	email;

	//getters
	string getFullName() const { return firstName + " " + lastName; }
};

class Teacher
{
	private:
		Demographics		_demographics;
		int					_id;
		vector<Classroom>	_classrooms;
		Teacher();

	public:
		~Teacher();
		Teacher(const Teacher &other);
		Teacher &operator=(const Teacher &other);
		Teacher(Demographics demographics);

		void setDemographics(Demographics demographics);

		void addClassroom(const Classroom &classroom);
		void addStudentToClassroom(const Student &s, unsigned int classroomIndex);

		Demographics getDemographics() const;

		vector<Classroom> getClassrooms() const;

};

#endif