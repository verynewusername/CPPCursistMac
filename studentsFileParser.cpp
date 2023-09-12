#include "Cursist.h"

void Cursist::studentsFileParser()
{

    if (d_lineBuffer == ".") {
        d_idBoxCounter = 1;
        d_studentsBuffer.clear();
        return;
    }
    else 
    {
        std::istringstream iss(d_lineBuffer);
        switch (d_idBoxCounter)
        {
        case 1:
            parseStudents(iss);
            ++d_idBoxCounter;
            break;
        case 2:
            if (d_lineBuffer == "group")
                d_groupFlag = true;
            else
                d_groupFlag = false;
            ++d_idBoxCounter;
            break;
        case 3:
            if (d_groupFlag) // get the results string
            {
                CPPGroup tempGroup;
                tempGroup.students = d_studentsBuffer;
                d_studentsBuffer.clear();
                tempGroup.gradeString = d_lineBuffer;

                d_groups.push_back(tempGroup);
            }
            ++d_idBoxCounter;
            break;
        case 4:
            d_groupFlag = false;
            ++d_idBoxCounter;
            break; 
        default:
            // Nothing needed to be done
            ++d_idBoxCounter;
            break;
        }    

    }
}