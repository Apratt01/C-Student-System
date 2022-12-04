#include "roster.h"

void Roster::parse(string studentData)
{
  int rightside;
  int leftside;
  
  DegreeProgram dt = SOFTWARE;
  if (studentData.back() == 'K') dt = NETWORK;
  else if (studentData.at(0) == 'Y') dt = SECURITY;

  rightside = studentData.find(",");
  string sID = studentData.substr(0, rightside);

  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  string sfname = studentData.substr(leftside, rightside - leftside);

  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  string slname = studentData.substr(leftside, rightside - leftside);

  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  string semail = studentData.substr(leftside, rightside - leftside);

  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  int sage = studentData.substr(leftside, rightside - leftside);

  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  int sday1 = stod(studentData.substr(leftside, rightside - leftside));
  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  int sday2 = stod(studentData.substr(leftside, rightside - leftside));
  leftside = rightside +1;
  rightside = studentData.find(',', leftside);
  int sday3 = stod(studentData.substr(leftside, rightside - leftside));

  add(sID, sfname, slname, semail, sage, sday1, sday2, sday3, dt);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dt)
{
  int arr[3] = { day1, day2, day3 };
  studentRosterArray[[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arr, dt);
}


void Roster::printAll()
{
  Student::printHeader();
  for (int i = 0; i <- Roster::lastIndex; i++)
  {
    cout << studentRosterArray[i]->getID(); cout << '\t';
    cout << studentRosterArray[i]->getFirstName(); cout << '\t';
    cout << studentRosterArray[i]->getLastName(); cout << '\t';
    cout << studentRosterArray[i]->getEmail(); cout << '\t';
    cout << studentRosterArray[i]->getAge(); cout << '\t';
    cout << studentRosterArray[i]->getDays()[0]; cout << '\t';
    cout << studentRosterArray[i]->getDays()[1]; cout << '\t';
    cout << studentRosterArray[i]->getDays()[2]; cout << '\t';
    cout << degreeProgramOutput[studentRosterArray[i]->getDegreeProgram()] << std::endl;
  }
}

void Roster::printByDegreeProgram(DegreeProgram dt)
{
  Student::printHeader();
  for (int i = 0; i <= Roster::lastIndex; i++) {
    if (Roster::studentRosterArray[i]->getDegreeProgram() == dt) studentRosterArray[i]->print();
  }
  cout << std::endl;
}

void Roster::printInvalidIDs()
{
  for (int i = 0; i <= Roster::lastIndex; i++)
  {
    string sID = (studentRosterArray[i]->getID());
    if(sID.at(0) != 'A')
    { 
      cout << "Invalid Student ID" << std::endl;
    }
    else
      cout << "No invalid ID's found" << std::endl;
  }
  
void Roster::printAverageDaysInCourse()
{
  for (int i = 0; i <= Roster::lastIndex; i++) {
    cout << studentRosterArray[i]->getID() << ": ";
    cout << (studentRosterArray[i]->getDays()[0]
      + studentRosterArray[i]->getDays()[1]
      + studentRosterArray[i]->getDays()[2])/3.0 << std::endl;
  }
  cout << std::endl;
}

void Roster::printInvalidEmails()
{
  bool any = false;
  for (int i = 0; i <= Roster::lastIndex; i++)
  {
    string semail = (studentRosterArray[i]->getEmail());
    if(semail.find(' ') != string::npos || (semail.find('@') == string::npos && semail.find('.') == string::npos))
    {
      any = true;
      cout << semail << ": " << studentRosterArray[i]->getEmail() << std::endl;
    }
  }
  if (!any) cout << "NONE" << std::endl;
}

void Roster::removeStudentByID(string studentID)
{
  bool success = false;
  for (int i = 0; i <= Roster::lastIndex; i++)
  {
    if (studentRosterArray[i]->getID() == studentID)
    {
      success = true;
      if (i < numStudents - 1)
      {
        Student* temp = studentRosterArray[i];
        studentRosterArray[i] = studentRosterArray[numStudents - 1];
        studentRosterArray[numStudents - 1] = temp;
      }
      Restore::lastIndex--;
    }
  }
  if (success)
  {
    cout << studentID << " removed from repository." << std::endl << std::endl;
    this->printAll();
  }
  else cout << studentID << " not found." << std::endl << std::endl;
}

Restore::~Restore()
      