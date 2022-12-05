#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

// D 1. Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
// student ID, first name, last name, email address, age, array of number of days to complete each course, degree program

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

// D 2. Create each of the following functions in the Student class: 
// D 2a. an accessor (i.e., getter) for each instance variable from part D1
// D 2b. a mutator (i.e., setter) for each instance variable from part D1
// D 2c. All external access and changes to any instance variables of the Student 
//       class must be done using accessor and mutator functions.
// D 2d. constructor using all of the input parameters provided in the table
// D 2e. print() to print specific student data

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