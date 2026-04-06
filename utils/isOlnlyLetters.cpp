
#include "../include/private_teacher.hpp"

bool    isOnlyLetters(const string &s) {
    for (char c : s)
    {
        if (!isalpha(static_cast<unsigned char>(c)))
            return (false);
    }
    return (!s.empty());
}
