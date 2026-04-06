#include "../include/Teacher.hpp"
#include "../include/Classroom.hpp"
#include "../include/Student.hpp"

Teacher::Teacher() : firstName(""), lastName("") {}
Teacher::~Teacher() {}
Teacher::Teacher(const Teacher &other) : firstName(other.firstName), lastName(other.lastName), classrooms(other.classrooms) {}
Teacher &Teacher::operator=(const Teacher &other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		classrooms = other.classrooms;
	}
	return (*this);
}
Teacher::Teacher(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName) {}

//setters
void Teacher::setFirstName(const string &firstName)
{
	this->firstName = firstName;
}
void Teacher::setLastName(const string &lastName)
{
	this->lastName = lastName;
}

void Teacher::addClassroom(const Classroom &c) { classrooms.push_back(c); }

void Teacher::addStudentToClassroom(const Student &s, unsigned int classroomIndex)
{
		classrooms[classroomIndex].addStudent(s);
}
//getters
string Teacher::getFirstName() const { return (firstName); }
string Teacher::getLastName() const { return (lastName); }
vector<Classroom> Teacher::getClassrooms() const { return (classrooms); }