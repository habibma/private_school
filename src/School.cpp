#include <algorithm>
#include "../include/School.hpp"
#include "../include/Classroom.hpp"

School::School() = default;
School::School(const std::string& name) : _name(name), _students(), _classrooms() {}
School::School(const School& other) = default;
School& School::operator=(const School& other) = default;
School::~School() = default;


// getters
std::string School::getName() const {
    return _name;
}
std::vector<Classroom>& School::getClassrooms() {
    return _classrooms;
}
const std::vector<Classroom>& School::getClassrooms() const {
    return _classrooms;
}
std::vector<Student> School::getStudents() const {
    return _students;
}
double School::getAverageGrade() const {
    if (_students.empty()) return 0.0;
    double total = 0.0;
    for (const auto& student : _students) {
        total += student.getGrade();
    }
    return total / _students.size();
}

double School::getHighestGrade() const {
    if (_students.empty()) return 0.0;
    double highest = _students[0].getGrade();
    for (const auto& student : _students) {
        if (student.getGrade() > highest) {
            highest = student.getGrade();
        }
    }
    return highest;
}

double School::getLowestGrade() const {
    if (_students.empty()) return 0.0;
    double lowest = _students[0].getGrade();
    for (const auto& student : _students) {
        if (student.getGrade() < lowest) {
            lowest = student.getGrade();
        }
    }
    return lowest;
}

// setters
void School::addClassroom(const Classroom& classroom) {
    _classrooms.push_back(classroom);
}

void School::addStudent(const Student& student) {
    _students.push_back(student);
}


//other methods
void School::resetSchool() {
    _name.clear();
    _students.clear();
    _classrooms.clear();
}

// removers
void School::removeClassroom(const std::string& subject) {
    _classrooms.erase(std::remove_if(_classrooms.begin(), _classrooms.end(),
                                      [&subject](const Classroom& c) { return c.getSubject() == subject; }),
                      _classrooms.end());
}