#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"
#include "../../include/ui/menu.hpp"

// Add a teacher to the school
void addTeacher(School &school)
{
    string firstName = getValidName("Write the teacher's first name: ");
    string lastName = getValidName("Write the teacher's last name: ");
    int age = getValidNumber("Write the teacher's age: ");
    string phoneNumber = getValidPhoneNumber("Write the teacher's phone number: ");
    string email = getValidEmail("Write the teacher's email: ");
    Demographics demographics{firstName, lastName, age, phoneNumber, email};
    Teacher teacher(demographics);
    school.addTeacher(teacher);
    cout << GREEN << "Teacher added successfully!" << endl
         << RESET;
}

void editTeacher(Teacher &teacher)
{
    string firstName = getValidName("Write the teacher's new first name (or press Enter to keep the current name): ");
    if (firstName.empty())
        firstName = teacher.getDemographics().firstName;
    string lastName = getValidName("Write the teacher's new last name (or press Enter to keep the current name): ");
    if (lastName.empty())
        lastName = teacher.getDemographics().lastName;
    int age = getValidNumber("Write the teacher's new age (or press Enter to keep the current age): ");
    if (age == 0)
        age = teacher.getDemographics().age;
    string phoneNumber = getValidPhoneNumber("Write the teacher's new phone number (or press Enter to keep the current phone number): ");
    if (phoneNumber.empty())
        phoneNumber = teacher.getDemographics().phoneNumber;
    string email = getValidEmail("Write the teacher's new email (or press Enter to keep the current email): ");
    if (email.empty())
        email = teacher.getDemographics().email;
    if (firstName.empty() && lastName.empty() && age == 0 && phoneNumber.empty() && email.empty())
    {
        cout << YELLOW << "No changes made to the teacher's information." << endl
             << RESET;
        return;
    }
    Demographics demographics{firstName, lastName, age, phoneNumber, email};
    teacher.setDemographics(demographics);
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
        {"ADD CLASS", "Add a classroom to the teacher's profile", [&teacher]() { addClassroom(teacher); }},
        {"ADD STUDENT", "Add a student to one of the teacher's classrooms", [&teacher]() { addStudentToClassroom(teacher); }},
        {"BACK", "Go back to the teachers", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("TEACHER MANAGEMENT", manageMenu);

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
            Demographics demographics = school.getTeachers()[i].getDemographics();
            cout << i + 1 << ". " << demographics.firstName << " " << demographics.lastName << endl;
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
        {"ADD TEACHER", "Add a teacher to the school", [&school]() { addTeacher(school); }},
        {"MANAGE TEACHERS", "Manage teachers", [&school]() { manageTeachers(school); }},
        {"BACK", "Go back to the main menu", [&shouldExit]() { shouldExit = true; }}
    };

    Menu menu("SCHOOL SETUP", buildMenu);

    while (!shouldExit)
    {
        menu.display();
    }
}
