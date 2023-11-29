#include "Cursist.h"

void Cursist::getGradeofStudent()
{
    // find the group if exists for the student d_studentsBuffer

    if (d_studentsBuffer.empty()) {
        d_groupFound = false;
        return;
    }

    std::vector<std::string> tempResults = findGradesofStudent(d_studentsBuffer.at(0));


    if (tempResults.empty())
    {
        d_outStudents << d_lineBuffer << '\n';
        // std::cout << "ERR: No group found for: " << d_studentsBuffer.at(0).studentID << '\n';
        // std::cout << "ERR: No group found for: " << d_lineBuffer << '\n';
        d_groupFound = false;
        return;
    }
    
    d_tempGrades = filterBest(tempResults);

    d_groupFound = true;
}