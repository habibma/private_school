#include "../include/MessageManager.hpp"
#include "../include/utils/Terminal.hpp"

void MessageManager::error(const std::string &message)
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

void MessageManager::success(const std::string &message)
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

void MessageManager::info(const std::string &message)
{
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20;
	std::string border(borderLength, '-');
	std::cout << CYAN << border << "\n" << RESET
			  << CYAN << BOLD << "INFO: " << RESET << CYAN << message << RESET << "\n"
			  << CYAN << border << "\n" << RESET;
	utils::pauseForInput();
}

void MessageManager::warning(const std::string &message)
{
	int msgLength = static_cast<int>(message.length());
	int borderLength = msgLength + 20;
	std::string border(borderLength, '-');

	std::cout << YELLOW << border << "\n" << RESET
			  << YELLOW << BOLD << "WARNING: " << RESET << YELLOW << message << RESET << "\n"
			  << YELLOW << border << "\n" << RESET;
	utils::pauseForInput();
}

void MessageManager::prompt(const std::string &message)
{
	std::cout << BLUE << message << RESET << std::endl;
}