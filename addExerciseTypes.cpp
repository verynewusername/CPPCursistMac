#include "Cursist.h"

void Cursist::addExerciseTypes()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }
    
    int resultsLength = d_tempGrades.length();

    if (resultsLength == 0)
        resultsLength = 8;

    for (int i = 0; i < resultsLength / 8; i++)
        d_outResults << ".....+++";

    d_outResults << " (exercise types)" << '\n';

}