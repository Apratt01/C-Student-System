#pragma once
#include "student.h"

// E. Create a Roster class (roster.cpp) by doing the following:
// E1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
// E2.  Create a student object for each student in the data table and populate classRosterArray.
// E2a. Parse each set of data identified in the “studentData Table.”
// E2b. Add each student object to classRosterArray.

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];

// E3.  Define the following functions:
// E3a. that sets the instance variables from part D1 and updates the roster.
// E3b. that removes students from the roster by student ID. If the student ID does not exist, 
//      the function prints an error message indicating that the student was not found.
// E3c. that prints a complete tab-separated list of student data in the provided format:
//      The printAll() function should loop through all the students in classRosterArray 
//      and call the print() function for each student.
// E3d. that correctly prints a student’s average number of days in the three courses.
//      The student is identified by the studentID parameter.
// E3e. that verifies student email addresses and displays all invalid email addresses to the user.
//      Note: A valid email should include an at sign('@') and period('.') and should not include a space(' ').
// E3f. that prints out student information for a degree program specified by an enumerated type.

public:
    void parse(string row);
    void add(string sID,
        string sfName,
        string slName,
        string semail,
        int sage,
        int sday1,
        int sday2,
        int sday3,
        DegreeProgram degreeprogram);
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    void printInvalidIDs();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void remove(string studentID);
    int getLastStudentIndex();
    Student* getStudent(int idx);
    ~Roster();
};