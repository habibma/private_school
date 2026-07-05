#include "../include/PageParser.hpp"
#include "TextManager.hpp"

#include <fstream>
#include <iostream>

namespace
{
	std::ifstream openPageFile(const std::string &filename)
	{
		std::ifstream file("./pages/" + filename);
		if (file.is_open())
			return file;

		file.open("pages/" + filename);
		return file;
	}

}

std::string PageParser::display(const std::string &filename)
{
	std::ifstream file = openPageFile(filename);
	if (!file.is_open())
	{
		return "Error: Could not open file " + filename;
	}

	std::string content;
	std::string line;
	while (std::getline(file, line))
	{
		content += line + "\n";
		if (line.empty())
		{
			TextManager::blankLine(); // Print a blank line for empty lines
			continue;
		}
		if (line.find("## ") == 0)
			TextManager::heading2(line.substr(3)); // Heading level 2
		else if (line.find("# ") == 0)
			TextManager::heading1(line.substr(2)); // Heading level 1
		else if (line.find("> ") == 0)
			TextManager::description(line.substr(2)); // Description
		else if (line.find("- ") == 0)
			TextManager::bulletPoint(line.substr(2)); // Regular text
		else
			TextManager::text(line); // Regular text
	}

	file.close();
	return content;
}