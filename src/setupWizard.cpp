#include "../include/setupWizard.hpp"
#include "../include/private_school.hpp"
#include "../include/MessageManager.hpp"

School runSetupWizard(SchoolManager& manager)
{
    // Display a welcome message for the setup wizard
    MessageManager::info("It looks like this is your first time running the program. Let's set up your school!");
    MessageManager::banner("=== SET UP YOUR SCHOOL ===");
    string schoolName = getValidName("Write the name of your school: ");
    School school(schoolName);
    manager.save(school);
    //buildSchool(school, manager);
    return school;
}
