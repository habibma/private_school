#include "../include/Teacher.hpp"
#include "../include/Classroom.hpp"
#include "../include/Student.hpp"

Teacher::Teacher() {}
Teacher::~Teacher() {}
Teacher::Teacher(const Teacher &other) : _demographics(other._demographics), _classrooms(other._classrooms) {
	_id = other._id;
}
Teacher &Teacher::operator=(const Teacher &other)
{
	if (this != &other)
	{
		_demographics = other._demographics;
		_classrooms = other._classrooms;
		_id = other._id;
	}
	return (*this);
}
Teacher::Teacher(Demographics demographics) : _demographics(demographics), _classrooms() {}

// setters
void Teacher::setDemographics(Demographics demographics) { this->_demographics = demographics; }

void Teacher::addClassroom(const Classroom &c) { this->_classrooms.push_back(c); }

void Teacher::addStudentToClassroom(const Student &s, unsigned int classroomIndex)
{
	this->_classrooms[classroomIndex].addStudent(s);
}

// getters
Demographics Teacher::getDemographics() const { return (this->_demographics); }

vector<Classroom> Teacher::getClassrooms() const { return (this->_classrooms); }