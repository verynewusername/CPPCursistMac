#include "Cursist.h"

bool Cursist::resultsField(std::string &input)
{
    // empty check
    if (input.empty())
        return false;

    if (input.at(0) == '.' || input.at(0) == '0' 
        || input.at(0) == '1' || input.at(0) == '?')
        return true;
    else
        return false;
}