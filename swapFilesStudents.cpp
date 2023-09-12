#include "Cursist.h"    // Cursist class

void Cursist::swapFilesStudents()
{
    std::remove ("admin/students");

    //copy "admin/students.out"  to "admin/students"
    std::ifstream  src("admin/students.out", std::ios::binary);
    std::ofstream  dst("admin/students",   std::ios::binary);

    dst << src.rdbuf();

    src.close();
    dst.close();

    std::remove ("admin/students.out");

}