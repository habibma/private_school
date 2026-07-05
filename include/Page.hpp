#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>
#include <vector>

struct MenuOption;
class MessageManager;
class School;


class	Page
{
	public:
		Page(const std::string &title, const std::string &description, const std::string &filename);

		void display() const;

	private:
		std::string _title;
		std::string _description;
		std::string _filename;
};

#endif
