#include "../include/MessageManager.hpp"
#include "../include/TextManager.hpp"

void MessageManager::error(const std::string &message)
{
	TextManager::error(message);
}

void MessageManager::success(const std::string &message)
{
	TextManager::success(message);
}

void MessageManager::info(const std::string &message)
{
	TextManager::info(message);
}

void MessageManager::warning(const std::string &message)
{
	TextManager::warning(message);
}

void MessageManager::prompt(const std::string &message)
{
	TextManager::prompt(message);
}

void MessageManager::banner(const std::string &message)
{
	TextManager::banner(message);
}
