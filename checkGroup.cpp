#include "Cursist.h"

std::vector<std::string> Cursist::checkGroup(std::vector<Student> &students)
{
    if (students.empty())
        return {};

    std::vector<std::string> grades = {};

    for (auto& group : d_groups)
    {
        for (auto& student : group.students)
        {
            //check if the student is the same with the first student in students
            if (student.studentID == students.at(0).studentID)
                grades.push_back(group.gradeString);
        }
    }

    return grades;
}