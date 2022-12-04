#include "roster.h"

void Roster::parse(string studentData)
{
    int rightside;
    int leftside;

    DegreeProgram degreeprogram = SOFTWARE;
    if (studentData.back() == 'K') degreeprogram = NETWORK;
    else if (studentData.at(0) == 'Y') degreeprogram = SECURITY;

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
    int sday1 = stod(studentData.substr(leftside, rightside - leftside));
    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sday2 = stod(studentData.substr(leftside, rightside - leftside));
    leftside = rightside + 1;
    rightside = studentData.find(',', leftside);
    int sday3 = stod(studentData.substr(leftside, rightside - leftside));

    add(sID, sfname, slname, semail, sage, sday1, sday2, sday3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int arr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arr, degreeprogram);
}


void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i < -Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getID(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getEmail(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]->getDays()[0]; cout << '\t';
        cout << classRosterArray[i]->getDays()[1]; cout << '\t';
        cout << classRosterArray[i]->getDays()[2]; cout << '\t';
        cout << degreeProgramOutput[classRosterArray[i]->getDegreeProgram()] << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidIDs()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
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

void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << classRosterArray[i]->getID() << ": ";
        cout << (classRosterArray[i]->getDays()[0]
            + classRosterArray[i]->getDays()[1]
            + classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
    }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string semail = (classRosterArray[i]->getEmail());
        if (semail.find(' ') != string::npos || (semail.find('@') == string::npos && semail.find('.') == string::npos))
        {
            any = true;
            cout << semail << ": " << classRosterArray[i]->getEmail() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
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
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from repository." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster() {}