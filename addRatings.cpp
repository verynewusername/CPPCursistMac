#include "Cursist.h"

void Cursist::addRatings()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }

    int length = d_groupofStudentBuffer.gradeString.length();

    for (int idx = 0; idx < length; idx++)
    {
        if (d_groupofStudentBuffer.gradeString[idx] == '.')
            d_outResults << ' ';
        else
            d_outResults << d_groupofStudentBuffer.gradeString[idx];
    }

    d_outResults << " (your ratings)" << '\n';

}