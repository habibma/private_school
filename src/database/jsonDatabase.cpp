#include "../../include/SchoolManager.hpp"
#include "../../include/database/JsonDatabase.hpp"
#include "external/json.hpp"
#include <fstream>
#include <sstream>


JsonDatabase::JsonDatabase(const std::string &filename) : _filename(filename) {}

bool JsonDatabase::load(SchoolManager& manager)
{
    std::ifstream file(_filename);
    if (!file)
        return true; // If the file doesn't exist, we consider it as a successful load with no data.

    json j;
    try
    {
        file >> j;
    }
    catch (const std::exception&)
    {
        return false;
    }

    if (!j.is_object() || !j.contains("schools") || !j["schools"].is_array())
        return false;

    for (const auto& schoolJson : j["schools"])
    {
        if (!schoolJson.is_object() || !schoolJson.contains("name") || !schoolJson["name"].is_string())
            continue;
        std::string name = schoolJson["name"];
        School school(name);

        if (!schoolJson.contains("classrooms") || !schoolJson["classrooms"].is_array())
        {
            manager.addSchool(school);
            continue;
        }

        for (const auto& classroomJson : schoolJson["classrooms"])
        {
            if (!classroomJson.is_object() || !classroomJson.contains("subject") || !classroomJson["subject"].is_string())
                continue;
            std::string subject = classroomJson["subject"];
            Classroom classroom(subject);

            if (classroomJson.contains("students") && classroomJson["students"].is_array())
            {
                for (const auto& studentJson : classroomJson["students"])
                {
                    if (!studentJson.is_object() || !studentJson.contains("name") || !studentJson["name"].is_string())
                        continue;
                    std::string studentName = studentJson["name"];
                    double grade = studentJson.value("grade", 0.0);
                    Student student(studentName, grade);
                    classroom.addStudent(student);
                }
            }
            school.addClassroom(classroom);
        }
        for (const auto& studentJson : schoolJson["students"])
        {
            if (!studentJson.is_object() || !studentJson.contains("name") || !studentJson["name"].is_string())
                continue;
            std::string studentName = studentJson["name"];
            double grade = studentJson.value("grade", 0.0);
            Student student(studentName, grade);
            school.addStudent(student);
        }
        manager.addSchool(school);
    }
    file.close();
    return true;
}

bool JsonDatabase::save(const SchoolManager& manager)
{
    json j;
    j["schools"] = json::array();
    for (const auto& school : manager.getSchools())
    {
        json schoolJson;
        schoolJson["name"] = school.getName();

        for (const auto& classroom : school.getClassrooms())
        {
            json classroomJson;
            classroomJson["subject"] = classroom.getSubject();

            for (const auto& student : classroom.getStudents())
            {
                json studentJson;
                studentJson["name"] = student.getName();
                studentJson["grade"] = student.getGrade();
                classroomJson["students"].push_back(studentJson);
                schoolJson["students"].push_back(studentJson);
            }
            schoolJson["classrooms"].push_back(classroomJson);
        }
        j["schools"].push_back(schoolJson);
    }

    std::ofstream file(_filename);
    if (!file)
        return false;

    file << j.dump(4); // Pretty print with 4 spaces indentation
    file.close();
    return true;
}
