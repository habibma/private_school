#include "../include/Teacher.hpp"
#include "../include/Student.hpp"

Teacher::Teacher() {}
Teacher::~Teacher() {}
Teacher::Teacher(const Teacher &other) : _demographics(other._demographics) {
	_id = other._id;
}
Teacher &Teacher::operator=(const Teacher &other)
{
	if (this != &other)
	{
		_demographics = other._demographics;
		_id = other._id;
	}
	return (*this);
}
Teacher::Teacher(Demographics demographics) : _demographics(demographics) {}

// setters
void Teacher::setDemographics(Demographics demographics) { this->_demographics = demographics; }

// getters
Demographics Teacher::getDemographics() const { return (this->_demographics); }
