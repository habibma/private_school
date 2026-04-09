#include "../include/School.hpp"
#include "../include/Classroom.hpp"

School::School(const std::string& name) : name(name) {}


// getters
std::string School::getName() const {
    return name;
}
std::vector<Teacher>& School::getTeachers() const {
    return const_cast<std::vector<Teacher>&>(teachers);
}

void School::addTeacher(const Teacher& teacher) {
    teachers.push_back(teacher);
}