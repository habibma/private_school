#include "../include/private_school.hpp"

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}
