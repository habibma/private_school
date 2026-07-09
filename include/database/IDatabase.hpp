#ifndef IDATABASE_HPP
# define IDATABASE_HPP

#include "SchoolManager.hpp"

class IDatabase
{
	public:
		virtual bool load(SchoolManager&) = 0;
		virtual bool save(const SchoolManager&) = 0;
		virtual ~IDatabase() = default;
};

#endif
