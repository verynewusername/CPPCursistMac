#include "Cursist.h"

void Cursist::addPercentages()
{

    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }

    d_outResults << "    5 points:";

    // get the results string length
    int resultsLength = d_groupofStudentBuffer.gradeString.length();

    double percentageFor8 = 0;

    for (int idx = 0; idx < resultsLength; idx++)
    {
        d_outResults << "  "; // Initial spacing

        for (; idx < idx + 8 && idx < resultsLength; idx++)
        {
            if (d_groupofStudentBuffer.gradeString[idx] == '1')
                percentageFor8 += 1;
            else if (d_groupofStudentBuffer.gradeString[idx] == '?')
                percentageFor8 += 0.5;
            else
                percentageFor8 += 0;
        }

        // Case for 3 - 5 points
        if (percentageFor8 > 3)
            percentageFor8 = 10 * (6 + (percentageFor8 - 3) / (5 - 3));
        else
            percentageFor8 = 10 * 2 * percentageFor8;
        

        if (percentageFor8 > 100)
            percentageFor8 = 100;

        // round to nearest int
        d_outResults << static_cast<int>(std::round(percentageFor8)) << "\%,";
        if (idx % 8 == 0)
            percentageFor8 = 0;
    }

    d_outResults << '\n';
}