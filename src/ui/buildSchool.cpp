#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"
#include "../../include/ui/menu.hpp"

// 1- add a classroom to the school
void addClassroomToSchool(School &school)
{
    string subject = getValidName("Write the subject of the class: ");
    Classroom classroom(subject);
    school.addClassroom(classroom);
    std::cout << GREEN << "Classroom added successfully!" << endl
         << RESET;
}

void addStudentToClassroom(Classroom &classroom)
{
    string studentName = getValidName("Write the student's name: ");;
    Student student(studentName);
    classroom.addStudent(student);
    std::cout << GREEN << "Student added successfully!" << endl
         << RESET;
}

void editClassroom(Classroom &classroom)
{
    string newSubject = getValidName("Write the new subject of the class: ");
    classroom.setSubject(newSubject);
    std::cout << GREEN << "Classroom updated successfully!" << endl
         << RESET;
}

void manageClassroom(Classroom &classroom)
{
    bool shouldExit = false;
    vector<MenuOption> manageMenu = {
        {"EDIT", "Edit the classroom's information", [&classroom]() { editClassroom(classroom); }},
        {"ADD STUDENT", "Add a student to the classroom", [&classroom]() { addStudentToClassroom(classroom); }},
        {"BACK", "Go back to the teachers", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("CLASSROOM MANAGEMENT", manageMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}

// To manage classrooms include editing information, adding students and teachers to the classroom,
// and deleting teachers from the school (CRUD operations)
void manageClassrooms(School &school)
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
        manageClassroom(classroom);
    }
}

// to handle building the school
void buildSchool(School &school)
{
    bool shouldExit = false;
    vector<MenuOption> buildMenu = {
        {"ADD CLASSROOM", "Add a classroom to the school", [&school]() { addClassroomToSchool(school); }},
        {"MANAGE CLASSROOMS", "Manage classrooms", [&school]() { manageClassrooms(school); }},
        {"BACK", "Go back to the main menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("SCHOOL SETUP", buildMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}
