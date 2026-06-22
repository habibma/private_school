# include "../include/MessageManager.hpp"

    void MessageManager::error(const std::string& message) {
		std::cout << RED << "Error: " << message << RESET << std::endl;
	}
	
	void MessageManager::success(const std::string& message) {
		std::cout << GREEN << message << RESET << std::endl;
	}

	void MessageManager::info(const std::string& message) {
		std::cout << CYAN << message << RESET << std::endl;
	}

	void MessageManager::warning(const std::string& message) {
		std::cout << YELLOW << "Warning: " << message << RESET << std::endl;
	}
	
	void MessageManager::prompt(const std::string& message) {
		std::cout << BLUE << message << RESET << std::endl;
	}