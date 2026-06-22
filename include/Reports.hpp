#ifndef REPORTS_HPP
# define REPORTS_HPP

#include <iostream>
#include "School.hpp"

namespace Reports
{
	void schoolSummary(const School&);
    void classrooms(const School&);
    void students(const School&);
    void statistics(const School&);
}

#endif