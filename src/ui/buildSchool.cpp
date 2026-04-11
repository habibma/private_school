#include "../../include/private_school.hpp"
#include "../../include/ui/buildSchool.hpp"

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
        return ;
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
        return ;
    }
    string studentName = getValidName("Write the student's name: ");
    double studentScore = getValidNumber("Write the student's score: ");
    Student student(studentName, studentScore);
    teacher.addStudentToClassroom(student, classroomIndex);
    cout << GREEN << "Student added successfully!" << endl
         << RESET;
}

// To manage the teachers include editing their information, adding classes to their profile, and adding students to their classes
// and deleting teachers from the school (CRUD operations)
void manageTeacher(Teacher &teacher)
{
    while (1)
    {
        cout << BOLD << "\n=== MANAGE TEACHER ===\n" << RESET;
        cout << "1. " << GREEN << "EDIT" << RESET << " - Edit teacher's information\n"
             << "2. " << CYAN << "ADD_CLASS" << RESET << " - Add a classroom to the teacher's profile\n"
             << "3. " << YELLOW << "ADD_STUDENT" << RESET << " - Add a student to a classroom\n"
             << "4. " << RED << "DELETE" << RESET << " - Delete the teacher from the school\n"
             << "5. BACK - Go back to the previous menu\n"
             << "> ";
        string prompt;
        getline(cin, prompt);
        if (prompt == "EDIT")
        {
            editTeacher(teacher);
        }
        else if (prompt == "ADD_CLASS")
        {
            addClassroom(teacher);
        }
        else if (prompt == "ADD_STUDENT")
        {
            addStudentToClassroom(teacher);
        }
        else if (prompt == "DELETE")
        {
            // To delete the teacher from the school, we will set the teacher's first name and last name to an empty string and clear their classrooms vector
            teacher.setFirstName("");
            teacher.setLastName("");
            teacher.getClassrooms().clear();
            cout << GREEN << "Teacher deleted successfully!" << endl
                 << RESET;
            return;
        }
        else if (prompt == "BACK")
        {
            return;
        }
        else
        {
            cout << RED << "Invalid input " << RESET
                        << "Please enter 'EDIT', 'ADD_CLASS', 'ADD_STUDENT', 'DELETE', or 'BACK'." << endl;

        }
    }
}

// to handle building the school
void buildSchool(School &school)
{
    // ADD to add a teacher, Manage to manage teachers, and BACK to go back to the main menu
    while (1)
    {
        cout << BOLD << "\n=== BUILD SCHOOL ===\n" << RESET
             << "1. " << GREEN << "ADD" << RESET << "    - Add a teacher to the school\n"
             << "2. " << CYAN << "MANAGE" << RESET << " - Manage teachers\n"
             << "3. " << RED << "BACK" << RESET << "   - Go back to the main menu\n"
             << BOLD << "Choose an option \n" << RESET
             << "> ";
        string prompt;
        getline(cin, prompt);
        if (prompt == "ADD")
            addTeacher(school);
        else if (prompt == "MANAGE")
        {
            // Edit a teacher's information; for now, we will only allow editing the teacher's name
            cout << "\nYour school has " << school.getTeachers().size() << " teacher(s)." << endl;
            for (size_t i = 0; i < school.getTeachers().size(); ++i)
            {
                cout << i + 1 << ". " << school.getTeachers()[i].getFirstName() << " " << school.getTeachers()[i].getLastName() << endl;
            }
            // Get the teacher index from the user or return to the previous menu
            int teacherIndex = getValidNumber("Enter the number of the teacher you want to manage (or 0 to go back): ") - 1;
            if (teacherIndex == -1)
            {
                continue;
            }
            if (teacherIndex < 0 || static_cast<size_t>(teacherIndex) >= school.getTeachers().size())
            {
                cout << RED << "Invalid teacher number. Please try again." << endl
                     << RESET;
                continue;
            }
            Teacher &teacher = school.getTeachers()[teacherIndex];
            // CRUD operations for the teacher
            manageTeacher(teacher);
        }
        else if (prompt == "BACK")
            return;
        else
            cout << RED << "Invalid input.\n" << RESET
                 << YELLOW << "Please enter 'ADD', 'MANAGE', or 'BACK'."  << RESET << endl;
    }
}