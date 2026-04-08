#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <string>
#include <vector>
#include "Teacher.hpp"

class School {
    public:
        School(const std::string& name);
        std::string getName() const;
        void build();
        void report() const;
        const std::vector<Teacher>& getTeachers() const;

    private:
        std::string name;
        std::vector<Teacher> teachers;
        void addTeacher();
        void addClassroom();
        //void addStudentToClassroom();
};

#endif