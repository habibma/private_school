
#include "../include/private_school.hpp"

bool    isOnlyLetters(const string &s) {
    for (char c : s)
    {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
            return (false);
    }
    return (true);
}
