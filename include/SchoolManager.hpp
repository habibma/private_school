#ifndef SCHOOL_MANAGER_HPP
# define SCHOOL_MANAGER_HPP

# include "School.hpp"
# include "private_school.hpp"

class   SchoolManager
{
    public:
        School  load();
        void    save(const School& school);
        bool    schoolExists();
        void    deleteSchoolData() {
            if (remove("./data/school_data.txt") == 0) {
                std::cout << GREEN << "School data deleted successfully!" << RESET << std::endl;
            } else {
                std::cout << RED << "Error: Could not delete school data from ./data/school_data.txt" << RESET << std::endl;
            }
        }
};

#endif


