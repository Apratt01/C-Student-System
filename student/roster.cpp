#include "roster.h"

// E. Create a Roster class (roster.cpp) by doing the following:
// E1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
// E2.  Create a student object for each student in the data table and populate classRosterArray.
// E2a. Parse each set of data identified in the “studentData Table.”
// E2b. Add each student object to classRosterArray.

void Roster::parse(string studentData)
{
    int rightside;
    int leftside;

    DegreeProgram degreeprogram = SOFTWARE;
    if (studentData.back() == 'K') degreeprogram = NETWORK;
    else if (studentData.back() == 'Y') degreeprogram = SECURITY;

    rightside = studentData.find(",");
    string sID = studentData.substr(0, rightside);

    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    string sfname = studentData.substr(leftside, rightside - leftside);

    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    string slname = studentData.substr(leftside, rightside - leftside);

    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    string semail = studentData.substr(leftside, rightside - leftside);

    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sage = stoi(studentData.substr(leftside, rightside - leftside));

    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sday1 = stoi(studentData.substr(leftside, rightside - leftside));
    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sday2 = stoi(studentData.substr(leftside, rightside - leftside));
    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sday3 = stoi(studentData.substr(leftside, rightside - leftside));

    add(sID, sfname, slname, semail, sage, sday1, sday2, sday3, degreeprogram);
}

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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int arr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arr, degreeprogram);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <=lastIndex; i++)
    {
        classRosterArray[i]->print();
    }
}



void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    Student::printHeader();
    for (int i = 0; i <= lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidIDs()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        string sID = (classRosterArray[i]->getID());
        if (sID.at(0) != 'A')
        {
            cout << "Invalid Student ID" << std::endl;
        }
        else
            cout << "No invalid ID's found" << std::endl;
    }
}

int Roster::getLastStudentIndex()
{
    return lastIndex;
}

Student* Roster::getStudent(int idx)
{
    return classRosterArray[idx];
}

void Roster::printAverageDaysInCourse(string studentID)
{
    int studentIndex = -1;
    for (int i = 0; i <= Roster::lastIndex; ++i)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            studentIndex = i;
            break;
        }
    }
    if (studentIndex >= 0)
    { 
        cout << classRosterArray[studentIndex]->getID() << ": ";
        cout << (classRosterArray[studentIndex]->getDays()[0]
            + classRosterArray[studentIndex]->getDays()[1]
            + classRosterArray[studentIndex]->getDays()[2]) / 3.0;
    }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        string semail = (classRosterArray[i]->getEmail());
        if (semail.find(' ') != string::npos || (semail.find('@') == string::npos && semail.find('.') == string::npos))
        {
            any = true;
            cout << semail << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from repository." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

// F5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

Roster::~Roster()
{
    for (int i = 0; i < numStudents; ++i)
    {
        delete classRosterArray[i];
    }
}