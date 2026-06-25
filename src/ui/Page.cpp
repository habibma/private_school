#include <fstream>
#include <exception>
#include <iostream>
#include "../include/ui/Page.hpp"
#include "TextManager.hpp"
#include "MessageManager.hpp"
#include "../include/ui/Menu.hpp"
#include "private_school.hpp"
#include "../include/utils/Terminal.hpp"


Page::Page(const std::string &title, const std::string &description, const std::string &filename)
	: _title(title), _description(description), _body("")
	{
		std::ifstream file("pages/" + filename);
		if (!file.is_open())
		{
			_body = "Unable to load page.";
			return;
		}
		std::string line;
		while (std::getline(file, line))
			_body += line + "\n";
	}

void Page::display() const
{
	TextManager::heading1(_title);
	TextManager::description(_description);

	TextManager::text(_body);
	utils::pauseForInput();
}
