#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <string>
#include <vector>
#include "Teacher.hpp"

class School {
    public:
        School(const std::string& name);
        std::string getName() const;
        std::vector<Teacher>& getTeachers() const;
        void addTeacher(const Teacher& teacher);


    private:
        std::string name;
        std::vector<Teacher> teachers;
    };

#endif