#include "Cursist.h"

void Cursist::outputResultsHelper()
{
    if (d_lineBuffer == "-------------------------------------") {
        d_idBoxCounter = 1;
        d_studentsBuffer.clear();
        d_groupFound = false;
        d_groupofStudentBuffer.gradeString.clear();
        d_outResults << d_lineBuffer << '\n';
        return;
    }
    else 
    {
        std::istringstream iss(d_lineBuffer);
        switch (d_idBoxCounter)
        {
        case 2: // student ID line
            // std::cout << "2\n";
            d_outResults << d_lineBuffer << '\n';
            parseStudents(iss);
            getGroupofStudent();
            ++d_idBoxCounter;
            break;

        case 4: // Percentages line
            // std::cout << "4\n";
            addPercentages();
            // d_outResults << d_lineBuffer << '\n';

            ++d_idBoxCounter;
            break;

        case 7: // question numberings line
            // std::cout << "7\n";
            addQuestionNumberings();
            ++d_idBoxCounter;
            break;

        case 8: // results line (your ratings)
            addRatings();
            ++d_idBoxCounter;
            break;

        case 9: // .....+++ {...} (exercise types)
            addExerciseTypes();
            ++d_idBoxCounter;
            break;
        default:
            d_outResults << d_lineBuffer << '\n';
            ++d_idBoxCounter;
            break;
        }    

    }
}