#ifndef MESSAGE_MANAGER_HPP
# define MESSAGE_MANAGER_HPP

#include "private_school.hpp"

class	MessageManager
{
	public:
    	static void error(const std::string& message);
		static void success(const std::string& message);
		static void info(const std::string& message);
		static void warning(const std::string& message);
		static void prompt(const std::string& message);
};

#endif // MESSAGE_MANAGER_HPP