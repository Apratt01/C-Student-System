#pragma once
#include "student.h"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];

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
    void printAverageDaysInCourse();
    void printInvalidEmails();
    void remove(string studentID);
    ~Roster();
};