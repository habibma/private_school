#include "../include/Student.hpp"
#include <stdexcept>

//constructors
Student::Student() : _name(""), _grade(0) {}

Student::Student(std::string name) : _name(name), _grade(0) {}

Student::Student(std::string name, double grade) {
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty.");
    if (grade < 0 || grade > 100)
        throw std::invalid_argument("Grade must be between 0 and 100.");
    _name = name;
    _grade = grade;
}
Student::Student(const Student &other) : _name(other._name), _grade(other._grade) {}
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
    return (*this);
}
Student::~Student() {}

//getters
std::string Student::getName() const { return (_name); }
double      Student::getGrade() const { return (_grade); }
