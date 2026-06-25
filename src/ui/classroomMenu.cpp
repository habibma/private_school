#include "../include/private_school.hpp"
#include "School.hpp"
#include "MessageManager.hpp"
#include "../include/ui/Menu.hpp"
#include "SchoolManager.hpp"


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

// To manage classrooms include editing information, adding students and teachers to the classroom,
// and deleting teachers from the school (CRUD operations)

void showClassroomMenu(Classroom &classroom, School &school, SchoolManager &manager)
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
        showClassroomMenu(classroom, school, manager);
    }
}