#include "Cursist.h"

void Cursist::addQuestionNumberings()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }

    int resultsLength = d_groupofStudentBuffer.gradeString.length();

    if (resultsLength == 0)
        resultsLength = 8;

    for (int idx = 0; idx < resultsLength; idx++)
        d_outResults << (idx + 1) % 10;

    d_outResults << "\n";
}
