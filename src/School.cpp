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

void School::setName(const std::string& name) {
    _name = name;
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

// Overloaded operator for outputting School information
std::ostream& operator<<(std::ostream& os, const School& school)
{
    os << "School Name: " << school.getName() << "\n";
    os << "Number of Classrooms: " << school.getClassrooms().size() << "\n";
    os << "Classrooms: ";
    for (const auto& classroom : school.getClassrooms()) {
        os << classroom.getSubject() << " ";
        for (const auto& student : classroom.getStudents()) {
            os << student.getName() << " (Grade: " << student.getGrade() << ") ";
        }
    }
    os << "\n";
    os << "Number of Students: " << school.getStudents().size() << "\n";
    os << "Students: ";
    for (const auto& student : school.getStudents()) {
        os << student.getName() << " (Grade: " << student.getGrade() << ") ";
    }
    os << "Average Grade: " << school.getAverageGrade() << "\n";
    os << "Highest Grade: " << school.getHighestGrade() << "\n";
    os << "Lowest Grade: " << school.getLowestGrade() << "\n";
    return os;
}
