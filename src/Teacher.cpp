#include "../include/Teacher.hpp"

Teacher::Teacher() : firstName(""), lastName(""), subject("") {}
Teacher::~Teacher() {}
Teacher::Teacher(const Teacher &other) : firstName(other.firstName), lastName(other.lastName), subject(other.subject), students(other.students) {}
Teacher &Teacher::operator=(const Teacher &other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		subject = other.subject;
		students = other.students;
	}
	return (*this);
}
Teacher::Teacher(const string &firstName, const string &lastName, const string &subject) : firstName(firstName), lastName(lastName), subject(subject) {}

//setters
void Teacher::setFirstName(const string &firstName)
{
	this->firstName = firstName;
}
void Teacher::setLastName(const string &lastName)
{
	this->lastName = lastName;
}
void Teacher::setSubject(const string &subject)
{
	this->subject = subject;
}

void Teacher::addStudent(const student &s) { students.push_back(s); }

//getters
string Teacher::getFirstName() const { return (firstName); }
string Teacher::getLastName() const { return (lastName); }
string Teacher::getSubject() const { return (subject); }
vector<student> Teacher::getStudents() const { return (students); }