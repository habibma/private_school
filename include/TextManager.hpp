#ifndef TEXT_MANAGER_HPP
#define TEXT_MANAGER_HPP

#include <string>

class TextManager
{
	public:
		static void	heading1(const std::string &text);
		static void	heading2(const std::string &text);
		static void	description(const std::string &text);
		static void	text(const std::string &text);

		static void	error(const std::string &message);
		static void	success(const std::string &message);
		static void	info(const std::string &message);
		static void	warning(const std::string &message);
		static void	prompt(const std::string &message);
		static void	banner(const std::string &message);
};

#endif
