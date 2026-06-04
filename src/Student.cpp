#include "../include/Student.hpp"
#include <stdexcept>

//constructors
Student::Student() : _name(""), _score(0) {}

Student::Student(std::string name) : _name(name), _score(0) {}

Student::Student(std::string name, double score) {
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty.");
    if (score < 0 || score > 100)
        throw std::invalid_argument("Score must be between 0 and 100.");
    _name = name;
    _score = score;
}
Student::Student(const Student &other) : _name(other._name), _score(other._score) {}
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        _name = other._name;
        _score = other._score;
    }
    return (*this);
}
Student::~Student() {}

//getters
std::string Student::getName() const { return (_name); }
double Student::getScore() const { return (_score); }