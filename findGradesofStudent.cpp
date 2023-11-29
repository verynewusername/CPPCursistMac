#include "Cursist.h"

std::vector<std::string> Cursist::findGradesofStudent(Student toSearch)
{
    if (toSearch.studentID == 0)
        return {};

    std::vector<std::string> grades = {};

    for (auto& group : d_groups)
    {
        for (auto& student : group.students)
        {
            //check if the student is the same with the first student in students
            if (student.studentID == toSearch.studentID)
                grades.push_back(group.gradeString);
        }
    }

    return grades;
}