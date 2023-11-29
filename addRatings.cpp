#include "Cursist.h"

void Cursist::addRatings()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }


    int length = d_tempGrades.length();

    for (int idx = 0; idx < length; idx++)
    {
        if (d_tempGrades[idx] == '.')
            d_outResults << ' ';
        else
            d_outResults << d_tempGrades[idx];
    }

    d_outResults << " (your ratings)" << '\n';

}