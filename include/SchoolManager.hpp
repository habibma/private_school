#ifndef SCHOOL_MANAGER_HPP
# define SCHOOL_MANAGER_HPP

# include "School.hpp"

class   SchoolManager
{
    public:
        School  load();
        void    save(const School& school);
        bool    schoolExists();
};

#endif


