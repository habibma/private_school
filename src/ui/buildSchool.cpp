#include "../../include/ui/buildSchool.hpp"

// to handle building the school
void buildSchool(School &school) {
	// ADD to add a teacher, Manage to manage teachers, and BACK to go back to the main menu
	while (1) {
		std::cout << YELLOW << "ADD to add a teacher, MANAGE to manage teachers, and BACK to go back to the main menu: " << RESET;
		string prompt;
		getline(cin, prompt);
		if (prompt == "ADD")
		{
			// Add a teacher to the school
            string	firstName		= getValidName("Write the teacher's first name: ");
            string	lastName		= getValidName("Write the teacher's last name: ");
            Teacher teacher(firstName, lastName);
            school.addTeacher(teacher);
            cout << GREEN << "Teacher added successfully!" << endl << RESET;
		}
		else if (prompt == "MANAGE")
		{
			// Edit a teacher's information; for now, we will only allow editing the teacher's name
            cout << "Your school has " << school.getTeachers().size() << " teacher(s)." << endl;
            for (size_t i = 0; i < school.getTeachers().size(); ++i) {
                cout << i + 1 << ". " << school.getTeachers()[i].getFirstName() << " " << school.getTeachers()[i].getLastName() << endl;
            }
            // Get the teacher index from the user or return to the previous menu
            int teacherIndex = getValidNumber("Enter the number of the teacher you want to manage (or 0 to go back): ") - 1;
            if (teacherIndex == -1) {
                continue; // Go back to the previous menu
            }
            if (teacherIndex < 0 || static_cast<size_t>(teacherIndex) >= school.getTeachers().size()) {
                cout << RED << "Invalid teacher number. Please try again." << endl << RESET;
                continue;
            }
            Teacher &teacher = school.getTeachers()[teacherIndex];
            // Edit the teacher's name
            string newFirstName = getValidName("Enter the new first name for the teacher (or press Enter to keep it unchanged): ");
            string newLastName = getValidName("Enter the new last name for the teacher (or press Enter to keep it unchanged): ");
            if (!newFirstName.empty()) {
                teacher.setFirstName(newFirstName);
            }
            if (!newLastName.empty()) {
                teacher.setLastName(newLastName);
            }
            cout << GREEN << "Teacher information updated successfully!" << endl << RESET;

		}
		else if (prompt == "BACK")
			return ;
		else
			cout << "Invalid input. Please enter 'ADD', 'MANAGE', or 'BACK'." << endl;
	}
}