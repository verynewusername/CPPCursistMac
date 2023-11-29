#include "Cursist.h"

void Cursist::addTenths()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }

    size_t length = d_tempGrades.length();
    size_t tenths = length / 10;

    for (size_t idx = 0; idx < tenths; idx++)
    {
        for (size_t idx2 = 0; idx2 < 9; idx2++)
        {
            d_outResults << ' ';
        }
        d_outResults << idx + 1;
    }

    d_outResults << "      \n";

}