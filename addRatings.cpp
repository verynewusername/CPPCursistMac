#include "Cursist.h"

void Cursist::addRatings()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }


    d_outResults << d_groupofStudentBuffer.gradeString 
        << " (your ratings)" << '\n';

}