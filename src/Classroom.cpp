#include "../include/Classroom.hpp"

// constructors and destructor
Classroom::Classroom(string subject) : _subject(subject) {}
Classroom::Classroom() : _subject("") {}
Classroom::~Classroom() {}

// getters
std::string Classroom::getSubject() const { return (_subject); }
std::vector<Student> Classroom::getStudents() const { return (students); }

// setters
void Classroom::setSubject(const string &subject) { _subject = subject; }

// other methods
void Classroom::addStudent(const Student &s) { students.push_back(s); }

double Classroom::getAverageGrade() const {
    if (students.empty()) {
        return 0.0; // Avoid division by zero
    }
    double totalGrade = 0.0;
    for (const auto& student : students) {
        totalGrade += student.getGrade();
    }
    return totalGrade / students.size();
}