#include <fstream>
#include <exception>
#include <iostream>
#include "Page.hpp"
#include "TextManager.hpp"
#include "MessageManager.hpp"
#include "../include/ui/Menu.hpp"
#include "private_school.hpp"
#include "../include/utils/Terminal.hpp"
#include "PageParser.hpp"


Page::Page(const std::string &title, const std::string &description, const std::string &filename)
	: _title(title), _description(description), _filename(filename) {}

void Page::display() const
{
	//TextManager::heading1(_title);
	//TextManager::description(_description);

	PageParser::display(_filename);

	utils::pauseForInput();
}
