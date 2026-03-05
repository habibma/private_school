#include "../include/Student.hpp"

Student::Student() : _name(""), _score(0.0) {}
Student::Student(string name, double score) : _name(name), _score(score) {}
Student::~Student() {}

//getters
string Student::getName() const { return (_name); }
double Student::getScore() const { return (_score); }