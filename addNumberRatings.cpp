#include "Cursist.h"

void Cursist::addNumberRatings()
{
    if (!d_groupFound)
    {
        d_outResults << d_lineBuffer << '\n';
        return;
    }

    d_outResults << "  Scores per set: ";

    // get the results string length
    int resultsLength = d_groupofStudentBuffer.gradeString.length();

    double basicCorrect = 0;
    double advancedCorrect = 0;

    for (int idx = 0; idx < resultsLength;)
    {
        basicCorrect = 0;
        advancedCorrect = 0;

        int temp = idx + 5;

        while (idx < temp && idx < resultsLength)
        {
            if (d_groupofStudentBuffer.gradeString.at(idx) == '1')
                basicCorrect += 1;
            else if (d_groupofStudentBuffer.gradeString.at(idx) == '?')
                basicCorrect += 0.5;

            // std::cout << "At: " << idx << " |" << d_groupofStudentBuffer.gradeString.at(idx) << "|\n";
            ++idx;
        }

        temp = idx + 3;

        while (idx < temp && idx < resultsLength)
        {
            if (d_groupofStudentBuffer.gradeString.at(idx) == '1')
                advancedCorrect += 1;
            else if (d_groupofStudentBuffer.gradeString.at(idx)  == '?')
                advancedCorrect += 0.5;

            ++idx;
        }

        d_outResults << basicCorrect << '+' << advancedCorrect << ", ";
    }

    d_outResults << '\n';
    

}