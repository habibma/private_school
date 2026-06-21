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

// setters
void School::addClassroom(const Classroom& classroom) {
    _classrooms.push_back(classroom);
}
