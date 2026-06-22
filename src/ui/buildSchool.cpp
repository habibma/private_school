#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"
#include "../../include/ui/Menu.hpp"
#include "../../include/SchoolManager.hpp"
#include "../../include/MessageManager.hpp"

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
    manager.save(school);
    MessageManager::success("Student '" + studentName + "' added successfully!");
}

void editClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    std::string newSubject = getValidName("Write the new subject of the class: ");
    classroom.setSubject(newSubject);
    manager.save(school);
    MessageManager::success("Classroom '" + newSubject + "' updated successfully!");
}

void manageClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    std::vector<MenuOption> manageMenu = {
        {"EDIT CLASSROOM", "Edit the classroom's information", [&classroom, &school, &manager]() { editClassroom(classroom, school, manager); }},
        {"ADD STUDENT", "Add a student to the classroom", [&classroom, &school, &manager]() { addStudentToClassroom(classroom, school, manager); }},
        {"BACK", "Go back to the school setup", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("CLASSROOM MANAGEMENT", manageMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}

// To manage classrooms include editing information, adding students and teachers to the classroom,
// and deleting teachers from the school (CRUD operations)
void manageClassrooms(School &school, SchoolManager &manager)
{
    while (true)
    {
        // list of classrooms in the school
        MessageManager::info("School " + school.getName() + " has " + std::to_string(school.getClassrooms().size()) + " classroom(s).");
        for (size_t i = 0; i < school.getClassrooms().size(); ++i)
        {
            std::cout << "\n" << std::setw(4) << std::left << (i + 1) << ". " << school.getClassrooms()[i].getSubject() << "\n" << std::endl;
        }
        int classroomIndex = getValidNumber("Enter the number of the classroom or 0 to cancel: ") - 1;
        if (classroomIndex == -1)
        {
            MessageManager::warning("Operation cancelled.");
            return;
        }
        if (classroomIndex < 0 || static_cast<size_t>(classroomIndex) >= school.getClassrooms().size())
        {
            MessageManager::error("Invalid classroom number. Please try again.");
            continue;
        }
        Classroom &classroom = school.getClassrooms()[classroomIndex];
        // manage the selected classroom
        manageClassroom(classroom, school, manager);
    }
}

// to handle building the school
void buildSchool(School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    std::vector<MenuOption> buildMenu = {
        {"ADD CLASSROOM", "Add a classroom to the school", [&school, &manager]() { addClassroomToSchool(school, manager); }},
        {"MANAGE CLASSROOMS", "Manage classrooms", [&school, &manager]() { manageClassrooms(school, manager); }},
        {"DELETE SCHOOL", "Delete all school data and start over", [&manager, &shouldExit]() { manager.deleteSchoolData(); shouldExit = true; }},
        {"BACK", "Go back to the main menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("SCHOOL SETUP", buildMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}
