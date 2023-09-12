#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>    // std::string
#include <vector>    // std::vector

struct Student {
    size_t studentID;
    std::string fullName;
};

struct CPPGroup {
    std::vector<Student> students;
    std::string gradeString;
};


#endif // STRUCTS_H
