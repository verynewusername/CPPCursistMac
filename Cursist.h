#ifndef CURSIST_H
#define CURSIST_H

#include "structs.h"    // Student and CPPGroup structs
#include <fstream>      // std::ifstream
#include <vector>       // std::vector
#include <string>       // std::string
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <iomanip>      // std::put_time
#include <cmath>        // std::round


class Cursist
{
    std::ifstream d_inStudents; // Input file stream Students
    std::ifstream d_inResults;  // Input file stream Results
    std::ofstream d_outStudents;// Output file stream Students
    std::ofstream d_outResults; // Output file stream Results

    std::vector<CPPGroup> d_groups; // Vector of CPPGroups

    bool d_initialSkip;             // Skip the first lines of the input file
    std::string d_lineBuffer;       // Buffer for the line

    std::vector<Student> d_studentsBuffer;  // Buffer for the students
    int d_idBoxCounter;                     // Counter for the id box
    bool d_groupFlag;                       // Flag for the group

    size_t d_numberOfParticipants;  // Number of participants
    CPPGroup d_groupofStudentBuffer;// Buffer for the group of the student
    bool d_groupFound;                // Flag for the group found

public:
    Cursist();              // Constructor
    ~Cursist() {};          // Destructor

    void runCursist();      // Run the cursist program

private:

    void getGroups();       // Get the group information from students
    void groupsPrinter();   // Print the groups to the console
    void studentsFileParser();  // Parse the students from the line
    void parseStudents(std::istringstream &iss); // Parse the line

    void outputStudents();  // Output the refreshed students to the output file
    void outputStudentsHelper(); // Helper function for outputStudents
    // Check the group of the student
    std::string checkGroup(std::vector<Student> &students); 
    bool resultsField(std::string &input); // check if line is a results field

    void outputResults();   // Output the new results to the output file
    void outputResultsHelper(); // Helper function for outputResults
    void addPercentages();  // Add the percentages to the output file
    void addQuestionNumberings(); // Add the question numberings to the output file
    void addRatings();      // Add the ratings to the output file
    void addExerciseTypes(); // Add the exercise types to the output file
    void getGroupofStudent(); // Get the group of the student

    void swapFilesStudents();// Swap the input and output files for students
    void swapFilesResults(); // Swap the input and output files for results

    // Check if string is a single repeated char
    bool singleRepeatedChar(std::string &input); 
    // Get the number of participants from the line
    void getNumberofParticipants(std::string &input);

    size_t ghostParticipants(); // Get the number of ghost participants

};


#endif // CURSIST_H
