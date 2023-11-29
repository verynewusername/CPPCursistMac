#include "Cursist.h"

std::string Cursist::filterBest(std::vector<std::string> &grades)
{
    if (grades.empty())
        return "";

    size_t lengthofSequence = 0;
    for (size_t idx = 0; idx < grades.size(); ++idx) 
    {
        if (grades.at(idx).length() >= lengthofSequence)
            lengthofSequence = grades.at(idx).length();
    }

    std::string ret = "";
    for (size_t idx = 0; idx < lengthofSequence; ++idx) 
    {
        if (grades.at(0).length() >= idx)
            ret += grades.at(0).at(idx);
        else
            ret += ".";
    }

    for (size_t idx = 0; idx < lengthofSequence; ++idx) 
    {
        for (size_t idx2 = 0; idx2 < grades.size(); ++idx2) 
        {
            if (grades.at(idx2).length() < idx)
                continue;

            switch (grades.at(idx2).at(idx))
            {
            case '1':
                if (ret[idx] == '0' || ret[idx] == '?' || ret[idx] == '.')
                    ret[idx] = '1';
            break;

            case '?':
                if (ret[idx] == '0' || ret[idx] == '.')
                    ret[idx] = '?';
            break;

            case '0':
                if (ret[idx] == '.')
                    ret[idx] = '0';
            break;

            default:
            break;
            }       
        }
    }

    return ret;
}
