#include "../include/private_school.hpp"
#include "School.hpp"
#include "MessageManager.hpp"
#include "../include/ui/Menu.hpp"
#include "SchoolManager.hpp"
#include "Classroom.hpp"
#include "Student.hpp"
#include "utils/Terminal.hpp"


void addStudentToClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    std::string studentName = getValidName("Write the student's name or press Enter to cancel: ");
    if (studentName.empty()) {
        MessageManager::warning("Operation cancelled.");
        return;
    }
    Student student(studentName);
    classroom.addStudent(student);
    school.addStudent(student);
    manager.setPrimarySchool(school);
    manager.save();
    MessageManager::success("Student '" + studentName + "' added successfully!");
}

void editClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    std::string newSubject = getValidName("Write the new subject of the class: ");
    classroom.setSubject(newSubject);
    manager.setPrimarySchool(school);
    manager.save();
    MessageManager::success("Classroom '" + newSubject + "' updated successfully!");
}

// To manage classrooms include editing information, adding students and teachers to the classroom,
// and deleting teachers from the school (CRUD operations)

void showClassroomMenu(Classroom &classroom, School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    std::vector<MenuOption> manageMenu = {
        {"EDIT CLASSROOM", "Edit the classroom's information", [&classroom, &school, &manager]() { editClassroom(classroom, school, manager); }},
        {"ADD STUDENT", "Add a student to the classroom", [&classroom, &school, &manager]() { addStudentToClassroom(classroom, school, manager); }},
        {"VIEW STUDENTS", "View the list of students in the classroom", [&classroom]() {
            classroom.getStudentList();
            utils::pauseForInput();
        }},
        {"ADD MATERIAL", "Add a material to the classroom", [&classroom, &school, &manager]() {
            std::string materialName = getValidName("Write the name of the material or press Enter to cancel: ");
            if (materialName.empty()) {
                MessageManager::warning("Operation cancelled.");
                return;
            }
            // Assuming Classroom has a method to add materials
            classroom.addMaterial(materialName);
            MessageManager::success("Material '" + materialName + "' added successfully!");
        }},
        {"DELETE CLASSROOM", "Delete the classroom from the school", [&classroom, &school, &manager, &shouldExit]() {
            school.removeClassroom(classroom.getSubject());
            manager.setPrimarySchool(school);
            manager.save();
            MessageManager::success("Classroom '" + classroom.getSubject() + "' deleted successfully!");
            shouldExit = true; // Exit after deletion
        }},
        {"BACK", "Go back to the school setup", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("CLASSROOM MANAGEMENT: " + classroom.getSubject(), manageMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}


void manageClassrooms(School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    std::vector<MenuOption> listOfClassrooms;

    if (school.getClassrooms().empty())
    {
        MessageManager::info("No classrooms available. Please add a classroom first.");
        return;
    }

    for (size_t i = 0; i < school.getClassrooms().size(); ++i)
    {
        listOfClassrooms.push_back({school.getClassrooms()[i].getSubject(), "Manage the classroom", [&school, &manager, i, &shouldExit]() {
                                  Classroom &classroom = school.getClassrooms()[i];
                                  showClassroomMenu(classroom, school, manager);
                              }});
    }

    listOfClassrooms.push_back({"BACK", "Go back to the school setup", [&shouldExit]() { shouldExit = true; }});

    Menu menu("MANAGE CLASSROOMS", listOfClassrooms);
    while (!shouldExit)
    {
        menu.display();
    }
}
