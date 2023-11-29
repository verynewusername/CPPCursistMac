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
    int resultsLength = d_tempGrades.length();

    double percentageFor8 = 0;
    double basicScore = 0;
    double advancedScore = 0;

    bool first = true;

    for (int idx = 0; idx < resultsLength;)
    {
        percentageFor8 = 0;
        basicScore = 0;
        advancedScore = 0;

        int temp = idx + 5;

        while (idx < temp && idx < resultsLength)
        {
            if (d_tempGrades.at(idx) == '1')
                basicScore += 1;
            else if (d_tempGrades.at(idx) == '?')
                basicScore += 0.5;

            // std::cout << "At: " << idx << " |" << d_tempGrades.at(idx) << "|\n";
            ++idx;
        }

        // Case for 3 - 5 points
        if (basicScore > 3)
            basicScore = 10 * (6 + (basicScore - 3) / (5 - 3));
        else
            basicScore = 10 * 2 * basicScore;

        temp = idx + 3;

        while (idx < temp && idx < resultsLength)
        {
            if (d_tempGrades.at(idx) == '1')
                advancedScore += 1;
            else if (d_tempGrades.at(idx)  == '?')
                advancedScore += 0.5;

            ++idx;
        }

        // std::cout << "For the grade String: |" << d_tempGrades << "|\n";
        // std::cout << "Basic score: " << basicScore << '\n';
        // std::cout << "Advanced score: " << advancedScore << '\n';

        percentageFor8 = basicScore + advancedScore * 20;
        

        if (percentageFor8 > 100)
            percentageFor8 = 100;

        if (percentageFor8 == 100)
        {
            if (first)
                d_outResults << " "; // Initial spacing
        }
        else if (percentageFor8 == 0)
            if (first)
                d_outResults << "   "; // Initial spacing
            else
                d_outResults << "  "; // Initial spacing
        else 
            d_outResults << "  "; // Initial spacing


        // round to nearest int
        // int roundedDownValue = static_cast<int>(std::round(percentageFor8));
        d_outResults << static_cast<int>(std::floor(percentageFor8)) << "\%,";
        first = false;
    }

    d_outResults << '\n';
}