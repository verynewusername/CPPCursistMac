#include "Cursist.h"

void Cursist::outputResults()
{ 
    // Get the current date and time
    std::time_t now = std::time(nullptr);

    d_outResults << "Cursist-Efe V1.1. ";
    // Format the date and time
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", std::localtime(&now));

    d_outResults << buffer << '\n';

    d_initialSkip = false;

    getline(d_inResults, d_lineBuffer);
    getline(d_inResults, d_lineBuffer);
    d_outResults << d_lineBuffer << '\n';
    getline(d_inResults, d_lineBuffer);
    d_outResults << d_lineBuffer << '\n';
    getNumberofParticipants(d_lineBuffer);

    while (getline(d_inResults, d_lineBuffer) && d_lineBuffer != "=================================================================")
    {
        // Skip the first lines of the input file
        if (!d_initialSkip)
        {
            // if the line only consists of the char "-"
            if (d_lineBuffer == "-----------------------------------------------------------------")
            {
                d_initialSkip = true;
                d_outResults << d_lineBuffer << '\n';
                // std::cout << "Initial skip done\n";
                // std::cout << d_lineBuffer << '\n';
                continue;
            }
            else
            {
                d_outResults << d_lineBuffer << '\n';
                d_idBoxCounter = 1;
                continue;
            }
        } 

        outputResultsHelper();
    }

    d_outResults << "=================================================================\n";

    int ghosts = ghostParticipants();
    
    d_outResults << ghosts << " of the " << d_numberOfParticipants
        << " participants (" << std::setprecision(2)
        << static_cast<double>(ghosts) / d_numberOfParticipants * 100 
        << "\%) did not submit exercises.\n\n";

    d_inResults.close();
    d_outResults.close();
}