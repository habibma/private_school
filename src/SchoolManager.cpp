#include "../include/SchoolManager.hpp"
#include "../include/Private_school.hpp"
#include "../include/School.hpp"

School SchoolManager::load()
{
    // check if the file "school_data" exists, if it does, load the data from it and return the school object, if it doesn't, return an empty school object
    if (fileExists("./data/school_data.txt"))
    {
        std::ifstream file("./data/school_data.txt");
        if (file.is_open())
        {
            std::string name;
            std::getline(file, name);
            School school(name);
            file.close();
            return school;
        }
    }
    return School();
}

void SchoolManager::save(const School& school)
{
    // save the data of the school in the file "school_data"
    std::ofstream file("./data/school_data.txt");
    if (file.is_open())
    {
        file << school.getName() << std::endl;
        file.close();
        std::cout << GREEN << "School data saved successfully!" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "Error: Could not save school data to ./data/school_data.txt" << RESET << std::endl;
    }
}

bool SchoolManager::schoolExists()
{
    // check if the file "school_data" exists, if it does, return true, if it doesn't, return false
    return fileExists("./data/school_data.txt");
}
