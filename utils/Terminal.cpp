#include "../include/utils/Terminal.hpp"

#include <iostream>
#include <limits>


void utils::clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void utils::pauseForInput()
{
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
