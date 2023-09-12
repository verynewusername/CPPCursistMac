#include "Cursist.h"

void Cursist::addQuestionNumberings()
{
    int resultsLength = d_groupofStudentBuffer.gradeString.length();

    for (int idx = 0; idx < resultsLength; idx++)
        d_outResults << (idx + 1) % 10;

    d_outResults << '\n';
}
