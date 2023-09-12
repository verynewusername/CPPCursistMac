#include "Cursist.h"

void Cursist::addExerciseTypes()
{
    int resultsLength = d_groupofStudentBuffer.gradeString.length();

    if (resultsLength == 0)
        resultsLength = 8;

    for (int i = 0; i < resultsLength / 8; i++)
        d_outResults << ".....+++";

    d_outResults << " (exercise types)" << '\n';

}