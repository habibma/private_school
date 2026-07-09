#include "../include/SchoolManager.hpp"
#include "../include/private_school.hpp"
#include "School.hpp"
#include "../include/MessageManager.hpp"
#include "database/JsonDatabase.hpp"

School SchoolManager::load()
{
    _schools.clear();
    JsonDatabase jsonDb("./data/school_data.json");
    if (!jsonDb.load(*this))
    {
        MessageManager::error("Could not load school data from ./data/school_data.json");
    }
    if (_schools.empty())
        return School();
    return _schools[0];
}

void SchoolManager::save()
{
    JsonDatabase jsonDb("./data/school_data.json");
    if (!jsonDb.save(*this))
    {
        MessageManager::error("Could not save school data to ./data/school_data.json");
    }
}

bool SchoolManager::schoolExists()
{
    // check if the file "school_data" exists, if it does, return true, if it doesn't, return false
    return fileExists("./data/school_data.json");
}

void SchoolManager::setPrimarySchool(const School& school)
{
    if (_schools.empty())
        _schools.push_back(school);
    else
        _schools[0] = school;
}


// getters
const std::vector<School>& SchoolManager::getSchools() const
{
    return _schools;
}

// setters
void SchoolManager::addSchool(const School& school)
{
    _schools.push_back(school);
}
