#include "Cursist.h"

void Cursist::outputStudentsHelper()
{
    if (d_lineBuffer == ".") {
        d_idBoxCounter = 1;
        d_studentsBuffer.clear();
        d_outStudents << d_lineBuffer << '\n';
        return;
    }
    else 
    {
        std::istringstream iss(d_lineBuffer);
        switch (d_idBoxCounter)
        {
        case 1:
            d_outStudents << d_lineBuffer << '\n';
            // std::cout << "sentiss: " << d_lineBuffer << '\n';
            parseStudents(iss);
            ++d_idBoxCounter;
            break;
        case 2:
            if (d_lineBuffer == "group")
                d_groupFlag = true;
            else
                d_groupFlag = false;
            ++d_idBoxCounter;
            d_outStudents << d_lineBuffer << '\n';
            break;
        case 3:
            if (d_lineBuffer[0] == '=')
            {
                d_outStudents << d_lineBuffer << '\n';
                ++d_idBoxCounter;
                break;
            }
            else
                [[fallthrough]];        
        default:
            if (resultsField(d_lineBuffer))
            {
                // std::cout << "sent info: " << d_lineBuffer << '\n';
                std::string tempResults = checkGroup(d_studentsBuffer);
                
                // check if there is a difference if yes report
                if (tempResults != std::string(d_lineBuffer)
                    && std::string(d_lineBuffer) != "" 
                        && tempResults != "")
                {
                    // Grade of student ... has changed to 

                    std::cout << "Grade of student " 
                        << d_studentsBuffer.at(0).studentID 
                        << " has changed from " << d_lineBuffer 
                        << " to " << tempResults << '\n';
                }

                if (tempResults != "")
                    d_outStudents << tempResults << '\n';
                else
                    d_outStudents << d_lineBuffer << '\n';
            }
            else
            {
                d_outStudents << d_lineBuffer << '\n';
            }
            ++d_idBoxCounter;
            break;
        }    

    }
}