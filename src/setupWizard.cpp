#include "../include/setupWizard.hpp"
#include "../include/ui/buildSchool.hpp"
#include "../include/Private_school.hpp"

School runSetupWizard(SchoolManager& manager)
{
    cout << YELLOW << "It looks like this is your first time running the program. Let's set up your school!" << RESET << endl;
    string schoolName = getValidName("Write the name of your school: ");
    School school(schoolName);
    manager.save(school);
    buildSchool(school, manager);
    return school;
}
