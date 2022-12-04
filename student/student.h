#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

class Student {
public:
    const static int daysInCourseArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[daysInCourseArraySize];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
    ~Student();

    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    void setID(string ID);
    void setFirstName(string fristName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge();
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram st);

    static void printHeader();

    void print();

};