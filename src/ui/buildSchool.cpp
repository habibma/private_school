#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"
#include "../../include/ui/menu.hpp"
#include "../../include/SchoolManager.hpp"

// 1- add a classroom to the school
void addClassroomToSchool(School &school, SchoolManager &manager)
{
    string subject = getValidName("Write the subject of the class or press Enter to cancel: ");
    if (subject.empty()) {
        std::cout << RED << "Operation cancelled." << RESET << std::endl;
        return;
    }
    Classroom classroom(subject);
    school.addClassroom(classroom);
    manager.save(school);
    std::cout << GREEN << "Classroom added successfully!" << endl
         << RESET;
}

void addStudentToClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    string studentName = getValidName("Write the student's name or press Enter to cancel: ");
    if (studentName.empty()) {
        std::cout << RED << "Operation cancelled." << RESET << std::endl;
        return;
    }
    Student student(studentName);
    classroom.addStudent(student);
    school.addStudent(student);
    manager.save(school);
    std::cout << GREEN << "Student added successfully!" << endl
         << RESET;
}

void editClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    string newSubject = getValidName("Write the new subject of the class: ");
    classroom.setSubject(newSubject);
    manager.save(school);
    std::cout << GREEN << "Classroom updated successfully!" << endl
         << RESET;
}

void manageClassroom(Classroom &classroom, School &school, SchoolManager &manager)
{
    bool shouldExit = false;
    vector<MenuOption> manageMenu = {
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
        cout << BOLD << "School " << school.getName() << " has " << school.getClassrooms().size() << " classroom(s)." << endl
             << RESET;
        for (size_t i = 0; i < school.getClassrooms().size(); ++i)
        {
            cout << i + 1 << ". " << school.getClassrooms()[i].getSubject() << endl;
        }
        int classroomIndex = getValidNumber("Enter the number of the classroom you want to manage (or 0 to go back): ") - 1;
        if (classroomIndex == -1)
        {
            return;
        }
        if (classroomIndex < 0 || static_cast<size_t>(classroomIndex) >= school.getClassrooms().size())
        {
            cout << RED << "Invalid classroom number. Please try again." << endl
                 << RESET;
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
    vector<MenuOption> buildMenu = {
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
