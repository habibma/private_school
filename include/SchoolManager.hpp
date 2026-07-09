#ifndef SCHOOL_MANAGER_HPP
# define SCHOOL_MANAGER_HPP

# include "School.hpp"
# include "private_school.hpp"

class   SchoolManager
{
    public:
        School  load();
        void    save();
        bool    schoolExists();
        void    setPrimarySchool(const School& school);
        void    deleteSchoolData() {
            if (remove("./data/school_data.json") == 0) {
                std::cout << GREEN << "School data deleted successfully!" << RESET << std::endl;
            } else {
                std::cout << RED << "Error: Could not delete school data from ./data/school_data.json" << RESET << std::endl;
            }
            _schools.clear();
        }

        // getters
        const std::vector<School>& getSchools() const;

        // setters
        void addSchool(const School& school);

    private:
        std::vector<School> _schools;
};

#endif


