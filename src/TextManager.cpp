
#include <iostream>
#include "../include/TextManager.hpp"
#include "../include/utils/Terminal.hpp"
#include "private_school.hpp"


void TextManager::heading1(const std::string &text)
{
	std::cout << "\n" << BOLD << text << RESET << std::endl;
}

void TextManager::heading2(const std::string &text)
{
	std::cout << UNDERLINE << text << RESET << std::endl;
}

void TextManager::blankLine()
{
	std::cout << std::endl;
}

void TextManager::bulletPoint(const std::string &text)
{
	std::cout << "	" << "- " << text << std::endl;
}

void TextManager::description(const std::string &text)
{
	//description in a box with a border amd tp and bottom margin of 1 line
	int msgLength = static_cast<int>(text.length());
	int borderLength = msgLength + 4; // 2 characters padding on each side
	std::string border(borderLength, '-');
	std::cout << "\n" << border << "\n"
			  << "| " << text << " |\n"
			  << border << "\n" << std::endl;
}

void TextManager::text(const std::string &text)
{
	std::cout << text << std::endl;
}

void TextManager::error(const std::string &message)
{
	utils::clearScreen();
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20; // 10 characters padding on each side
	std::string border(borderLength, '-');
	std::cout << RED << border <<"\n" << RESET
			  << RED << BOLD << "ERROR: " << RESET << RED << message << RESET << "\n"
			  << RED << border << "\n" << RESET;
	utils::pauseForInput();
}

void TextManager::success(const std::string &message)
{
	utils::clearScreen();
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20;
	std::string border(borderLength, '-');

	std::cout << GREEN << border <<"\n" << RESET
			  << GREEN << BOLD << "SUCCESS: " << RESET << GREEN << message << RESET << "\n"
			  << GREEN << border << "\n" << RESET;
	utils::pauseForInput();
}

void TextManager::info(const std::string &message)
{
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20;
	std::string border(borderLength, '-');
	std::cout << CYAN << border << "\n" << RESET
			  << CYAN << BOLD << "INFO: " << RESET << CYAN << message << RESET << "\n"
			  << CYAN << border << "\n" << RESET;
	utils::pauseForInput();
}

void TextManager::warning(const std::string &message)
{
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20;
	std::string border(borderLength, '-');

	std::cout << YELLOW << border << "\n" << RESET
			  << YELLOW << BOLD << "WARNING: " << RESET << YELLOW << message << RESET << "\n"
			  << YELLOW << border << "\n" << RESET;
	utils::pauseForInput();
}

void TextManager::prompt(const std::string &message)
{
	std::cout << BLUE << message << RESET << std::endl;
}

void TextManager::banner(const std::string &message)
{
	utils::clearScreen();
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20; // 10 characters padding on each side
	std::string border(borderLength, '=');
	std::cout << MAGENTA << border << "\n" << RESET
			  << MAGENTA << BOLD << message << RESET << "\n"
			  << MAGENTA << border << "\n" << RESET;

	utils::pauseForInput();
}

