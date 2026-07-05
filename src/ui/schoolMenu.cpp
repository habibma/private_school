#include "../include/ui/schoolMenu.hpp"
#include "School.hpp"
#include "SchoolManager.hpp"
#include "../include/ui/Menu.hpp"
#include "../include/ui/classroomMenu.hpp"
#include "MessageManager.hpp"

// 1- add a classroom to the school
void addClassroomToSchool(School &school, SchoolManager &manager)
{
    std::string subject = getValidName("Write the subject of the class or press Enter to cancel: ");
    if (subject.empty()) {
        MessageManager::warning("Operation cancelled.");
        return;
    }
    Classroom classroom(subject);
    school.addClassroom(classroom);
    manager.save(school);
    MessageManager::success("Classroom '" + subject + "' added successfully!");
}

void editSchoolName(School &school, SchoolManager &manager)
{
    std::string newName = getValidName("Write the new name of the school: ");
    if (newName.empty()) {
        MessageManager::warning("Operation cancelled.");
        return;
    }
    school = School(newName); // Recreate the school with the new name
    manager.save(school);
    MessageManager::success("School name updated to '" + newName + "' successfully!");
}

void showSchoolMenu(School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    std::vector<MenuOption> schoolMenu = {
        {"ADD CLASSROOM", "Add a classroom to the school", [&school, &manager]() { addClassroomToSchool(school, manager); }},
        {"MANAGE CLASSROOMS", "Manage classrooms", [&school, &manager]() { manageClassrooms(school, manager); }},
        {"EDIT SCHOOL NAME", "Edit the name of the school", [&school, &manager]() { editSchoolName(school, manager); }},
        {"DELETE SCHOOL", "Delete all school data and start over", [&manager, &shouldExit]() { manager.deleteSchoolData(); shouldExit = true; }},
        {"BACK", "Go back to the main menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("SCHOOL SETUP", schoolMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}
