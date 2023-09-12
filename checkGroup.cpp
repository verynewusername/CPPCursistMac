#include "Cursist.h"

std::string Cursist::checkGroup(std::vector<Student> &students)
{
    if (students.empty())
        return "";

    for (auto& group : d_groups)
    {
        for (auto& student : group.students)
        {
            //check if the student is the same with the first student in students
            if (student.studentID == students.at(0).studentID)
                return group.gradeString;
        }
    }

    return "";
}