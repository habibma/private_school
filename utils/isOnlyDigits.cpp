#include "../include/private_school.hpp"

bool    isOnlyDigits(const string &s) {
    for (char c : s)
    {
        if (!isdigit(static_cast<unsigned char>(c)))
            return (false);
    }
    return (true);
}
