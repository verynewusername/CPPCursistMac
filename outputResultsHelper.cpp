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
            getGradeofStudent();
            ++d_idBoxCounter;
            break;
        
        case 3: //Ratings
            addNumberRatings();
            ++d_idBoxCounter;
            break;
        case 5: // Percentages line
            addPercentages();
            ++d_idBoxCounter;
            break;

        // case 6: 
        //     d_outResults << '\n'; // add a newline
        //     ++d_idBoxCounter;

        case 7: // 1,2,3 written line for tenths
            addTenths();
            ++d_idBoxCounter;
            break;
        case 8: // question numberings line
            // std::cout << "7\n";
            addQuestionNumberings();
            ++d_idBoxCounter;
            break;

        case 9: // results line (your ratings)
            addRatings();
            ++d_idBoxCounter;
            break;

        case 10: // .....+++ {...} (exercise types)
            addExerciseTypes();
            ++d_idBoxCounter;
            break;
        default:
            // d_outResults << d_lineBuffer << d_idBoxCounter << '\n';
            d_outResults << d_lineBuffer << '\n';
            ++d_idBoxCounter;
            break;
        }    

    }
}