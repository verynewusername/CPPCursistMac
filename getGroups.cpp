#include "Cursist.h"

void Cursist::getGroups()
{
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
                d_idBoxCounter = 1;
                continue;
            }
        }

        // std::cout << d_lineBuffer << '\n';

        studentsFileParser();    
        
    }
}
