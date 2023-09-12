#include "Cursist.h"

void Cursist::getNumberofParticipants(std::string &input)
{
    //get the last word in the string
    std::string lastWord;
    std::istringstream iss(input);
    while (iss >> lastWord) {}
    // std::cout << lastWord << '\n';

    d_numberOfParticipants = std::stoi(lastWord);
}