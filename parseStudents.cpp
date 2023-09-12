#include "Cursist.h"

#include "Cursist.h"

void Cursist::parseStudents(std::istringstream &iss)
{
    std::string tempinput;
    while (getline(iss, tempinput, ','))
    {
        std::istringstream recordStream(tempinput);
        Student tempStudent;

        if (recordStream >> tempStudent.studentID)
        {
            // Read the rest of the line as a single string (rest)
            getline(recordStream >> std::ws, tempStudent.fullName);

            d_studentsBuffer.push_back(tempStudent);
        }
    }
}