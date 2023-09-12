#include "Cursist.h"

void Cursist::groupsPrinter()
{
    for (auto &group : d_groups)
    {
        for (auto &student : group.students)
        {
            std::cout << student.studentID << ' ';
            std::cout << student.fullName << '\n';
        }
        
        std::cout << group.gradeString << '\n';
    }
}