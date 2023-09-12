#include "Cursist.h"

void Cursist::getGroupofStudent()
{
    // find the group if exists for the student d_studentsBuffer

    if (d_studentsBuffer.empty()) {
        d_groupFound = false;
        return;
    }

    size_t studentID = d_studentsBuffer.at(0).studentID;

    // std::cout << "studentID: " << studentID << '\n';

    for (auto &group : d_groups) {
        for (auto &student : group.students) {
            if (student.studentID == studentID) {
                d_groupFound = true;
                d_groupofStudentBuffer = group;
                return;
            }
        }
    }

    d_groupFound = false;
}