#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <string>
#include <vector>
#include "Classroom.hpp"
#include "Student.hpp"

class School {
    public:
        //constructors
        School();
        School(const std::string& name);
        School(const School& other);
        School& operator=(const School& other);
        ~School();

        //getters
        std::string getName() const;
        std::vector<Classroom>& getClassrooms();
        const std::vector<Classroom>& getClassrooms() const;
        std::vector<Student> getStudents() const;

        //setters
        void    addClassroom(const Classroom& classroom);
        void    addStudent(const Student& student);
        void    addStudentToClassroom(const Student& student, const std::string& classroomSubject);

    private:
        std::string _name;
        std::vector<Student> _students;
        std::vector<Classroom> _classrooms;
};

#endif