#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"
#include "../../include/ui/menu.hpp"

// Add a teacher to the school
void addTeacher(School &school)
{
    string firstName = getValidName("Write the teacher's first name: ");
    string lastName = getValidName("Write the teacher's last name: ");
    Teacher teacher(firstName, lastName);
    school.addTeacher(teacher);
    cout << GREEN << "Teacher added successfully!" << endl
         << RESET;
}

void editTeacher(Teacher &teacher)
{
    string firstName = getValidName("Write the teacher's new first name (or press Enter to keep the current name): ");
    string lastName = getValidName("Write the teacher's new last name (or press Enter to keep the current name): ");
    teacher.setFirstName(firstName);
    teacher.setLastName(lastName);
    cout << GREEN << "Teacher information updated successfully!" << endl
         << RESET;
}

void addClassroom(Teacher &teacher)
{
    string subject = getValidName("Write the subject of the class: ");
    Classroom classroom(subject);
    teacher.addClassroom(classroom);
    cout << GREEN << "Classroom added successfully!" << endl
         << RESET;
}

void addStudentToClassroom(Teacher &teacher)
{
    if (teacher.getClassrooms().empty())
    {
        cout << RED << "No classrooms available. Please add a classroom first." << endl
             << RESET;
        return;
    }
    cout << BOLD << "Select a classroom to add a student to:" << endl
         << RESET;
    for (size_t i = 0; i < teacher.getClassrooms().size(); ++i)
    {
        cout << i + 1 << ". " << teacher.getClassrooms()[i].getSubject() << endl;
    }
    int classroomIndex = getValidNumber("Enter the number of the classroom: ") - 1;
    if (classroomIndex < 0 || static_cast<size_t>(classroomIndex) >= teacher.getClassrooms().size())
    {
        cout << RED << "Invalid classroom number. Please try again." << endl
             << RESET;
        return;
    }
    string studentName = getValidName("Write the student's name: ");
    double studentScore = getValidNumber("Write the student's score: ");
    Student student(studentName, studentScore);
    teacher.addStudentToClassroom(student, classroomIndex);
    cout << GREEN << "Student added successfully!" << endl
         << RESET;
}

void manageTeacher(Teacher &teacher)
{
    bool shouldExit = false;
    vector<MenuOption> manageMenu = {
        {"EDIT", "Edit the teacher's information", [&teacher]() { editTeacher(teacher); }},
        {"ADD_CLASS", "Add a classroom to the teacher's profile", [&teacher]() { addClassroom(teacher); }},
        {"ADD_STUDENT", "Add a student to one of the teacher's classrooms", [&teacher]() { addStudentToClassroom(teacher); }},
        {"BACK", "Go back to the previous menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("MANAGE TEACHER", manageMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}

// To manage the teachers include editing their information, adding classes to their profile, and adding students to their classes
// and deleting teachers from the school (CRUD operations)
void manageTeachers(School &school)
{
    while (true)
    {
        // list of teachers in the school
        cout << BOLD << "Your school has " << school.getTeachers().size() << " teacher(s)." << endl
             << RESET;
        for (size_t i = 0; i < school.getTeachers().size(); ++i)
        {
            cout << i + 1 << ". " << school.getTeachers()[i].getFirstName() << " " << school.getTeachers()[i].getLastName() << endl;
        }
        int teacherIndex = getValidNumber("Enter the number of the teacher you want to manage (or 0 to go back): ") - 1;
        if (teacherIndex == -1)
        {
            return;
        }
        if (teacherIndex < 0 || static_cast<size_t>(teacherIndex) >= school.getTeachers().size())
        {
            cout << RED << "Invalid teacher number. Please try again." << endl
                 << RESET;
            continue;
        }
        Teacher &teacher = school.getTeachers()[teacherIndex];
        // manage the selected teacher
        manageTeacher(teacher);
    }
}

// to handle building the school
void buildSchool(School &school)
{
    bool shouldExit = false;
    vector<MenuOption> buildMenu = {
        {"ADD", "Add a teacher to the school", [&school]() { addTeacher(school); }},
        {"MANAGE", "Manage teachers", [&school]() { manageTeachers(school); }},
        {"BACK", "Go back to the main menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("BUILD SCHOOL", buildMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}
