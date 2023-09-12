#include "Cursist.h"

bool Cursist::singleRepeatedChar(std::string &input)
{
    if (input.length() < 10) {
        return false; // A string with less than 10 characters cannot consist of repeated characters.
    }

    char firstChar = input[0];

    for (size_t i = 1; i < input.length(); ++i) {
        // Skip spaces in the input string
        if (input[i] != '-') {
            continue;
        }

        if (input[i] != firstChar) {
            return false; // If any non-space character doesn't match the first character, it's not a single repeated character.
        }
    }

    return true;
}