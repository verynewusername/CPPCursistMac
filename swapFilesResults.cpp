#include "Cursist.h"    // Cursist class

void Cursist::swapFilesResults()
{
    std::remove ("admin/results");

    //copy "admin/results.out"  to "admin/results"
    std::ifstream  src("admin/results.out", std::ios::binary);
    std::ofstream  dst("admin/results",   std::ios::binary);

    dst << src.rdbuf();

    src.close();
    dst.close();

    std::remove ("admin/results.out");

}