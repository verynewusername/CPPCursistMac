#include "Cursist.h"

void Cursist::outputStudents()
{
    d_inStudents.clear(); // Clear any end-of-file flags
    d_inStudents.seekg(0, std::ios::beg); // pointer to the beginning

    while (getline(d_inStudents, d_lineBuffer))
    {
        // Skip the first lines of the input file
        if (!d_initialSkip)
        {
            // while line is not ".\n" skip
            if (d_lineBuffer == "."){
                d_initialSkip = true;
                // std::cout << d_lineBuffer << '\n';    
            }
            else
            {
                d_outStudents << d_lineBuffer << '\n';
                d_idBoxCounter = 1;
                continue;
            }
        }
            

        outputStudentsHelper(); 
    }

    d_inStudents.close();
    d_outStudents.close();
}