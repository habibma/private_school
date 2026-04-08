#include "../include/Classroom.hpp"

Classroom::Classroom(string subject) : _subject(subject) {}
Classroom::Classroom() : _subject("") {}
Classroom::~Classroom() {}

void Classroom::setSubject(const string &subject) { _subject = subject; }
string Classroom::getSubject() const { return (_subject); }

void Classroom::addStudent(const Student &s) { students.push_back(s); }
vector<Student> Classroom::getStudents() const { return (students); }

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