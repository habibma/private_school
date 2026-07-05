#include <iostream>
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


// getters
void Classroom::getStudentList() const {
    if (students.empty()) {
        std::cout << "No students in this classroom." << std::endl;
        return;
    }
    std::cout << "Students in " << _subject << ":\n";
    for (const auto &student : students) {
        std::cout << "- " << student.getName() << " (Grade: " << student.getGrade() << ")\n";
    }
}

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

void Classroom::addMaterial(const string &material) {
    _material = material;
}
