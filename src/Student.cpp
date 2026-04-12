#include "../include/Student.hpp"
#include <stdexcept>

Student::Student() {}
Student::Student(string name, double score) {
    if (name.empty())
        throw invalid_argument("Name cannot be empty.");
    if (score < 0 || score > 100)
        throw invalid_argument("Score must be between 0 and 100.");
    _name = name;
    _score = score;
}
Student::~Student() {}

//getters
string Student::getName() const { return (_name); }
double Student::getScore() const { return (_score); }