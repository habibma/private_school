#include "../include/School.hpp"
#include "../include/Classroom.hpp"

School::School(const std::string& name) : name(name) {}

std::string School::getName() const {
    return name;
}

void School::addTeacher() {
    string	firstName		= getValidName("Write the teacher's first name: ");
    string	lastName		= getValidName("Write the teacher's last name: ");
    Teacher teacher(firstName, lastName);
    teachers.push_back(teacher);
}

void School::report() const {
    std::cout << "School Name: " << name << std::endl;
    for (const auto& teacher : teachers) {
        std::cout << "Teacher: " << teacher.getFirstName() << " " << teacher.getLastName() << std::endl;
        for (const auto& classroom : teacher.getClassrooms()) {
            std::cout << "  Classroom: " << classroom.getSubject() << std::endl;
            std::cout << "    Average Score: " << classroom.getAverageScore() << std::endl;
        }
    }
}

void School::addClassroom()
{
    cout << "Your school has " << teachers.size() << " teacher(s)." << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        cout << i + 1 << ". " << teachers[i].getFirstName() << " " << teachers[i].getLastName() << endl;
    }
    int teacherIndex = getValidNumber("Select a teacher to add a classroom to (enter the number): ") - 1;
    if (teacherIndex < 0 || teacherIndex >= static_cast<int>(teachers.size())) {
        cout << "Invalid teacher selection. Please try again." << endl;
        return;
    }
    string subject = getValidName("What is the subject of the classroom? ");
    Classroom classroom(subject);
    teachers[teacherIndex].addClassroom(classroom);
    cout << GREEN << "Classroom added successfully!" << endl << RESET;
}

void School::build() {
    addTeacher();
    addClassroom();
    //addStudentToClassroom();
}

const std::vector<Teacher>& School::getTeachers() const {
    return teachers;
}

