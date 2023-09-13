#include "Cursist.h"    // Cursist class

void Cursist::runCursist(int arg, char **argv)
{
    std::cout << "Running cursist\n";
    getGroups();

    if (arg > 1)
    {
        std::string arg1 = argv[1];
        if (arg1 == "-g")
        {
            groupsPrinter();
        }
        else if (arg1 == "-s")
        {
            std::cout << "Outputting students only\n";
            outputStudents();
            swapFilesStudents();
            std::remove ("admin/results.out");
        }
        else if (arg1 == "-r")
        {
            outputResults();
            swapFilesResults();
            std::remove ("admin/students.out");
        }
        else
        {
            std::cout << "Invalid argument\n";
        }
    }
    else 
    {
        outputStudents();
        outputResults();

        swapFilesStudents();
        swapFilesResults();
    }
}