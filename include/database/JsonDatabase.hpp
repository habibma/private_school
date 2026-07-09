#ifndef JSON_DATABASE_HPP
# define JSON_DATABASE_HPP

#include <string>
#include "IDatabase.hpp"

class SchoolManager;

class JsonDatabase : public IDatabase
{
public:
	JsonDatabase(const std::string &filename);

	bool load(SchoolManager &manager);
	bool save(const SchoolManager &manager);

private:
	std::string _filename;
};

#endif
