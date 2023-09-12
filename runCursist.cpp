#include "Cursist.h"    // Cursist class

void Cursist::runCursist()
{
    std::cout << "Running cursist\n";
    getGroups();

    outputStudents();

    outputResults();

    swapFilesStudents();
    swapFilesResults();
}