#include "../include/Classroom.hpp"

// constructors and destructor
Classroom::Classroom(string subject) : _subject(subject) {}
Classroom::Classroom() : _subject("") {}
Classroom::~Classroom() {}

// getters
string Classroom::getSubject() const { return (_subject); }
vector<Student> Classroom::getStudents() const { return (students); }

// setters
void Classroom::setSubject(const string &subject) { _subject = subject; }

// other methods
void Classroom::addStudent(const Student &s) { students.push_back(s); }

double Classroom::getAverageScore() const {
    if (students.empty()) {
        return 0.0; // Avoid division by zero
    }
    double totalScore = 0.0;
    for (const auto& student : students) {
        totalScore += student.getScore();
    }
    return totalScore / students.size();
}