#include "roster.h"

// F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, 
//     which will contain the required function calls to achieve the following results:


int main()
{
    const string studentData[] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Aileen,Pratt,aprat71@wgu.edu,47,24,48,85,SOFTWARE"
    };

// F1. Print out to the screen, via your application, the course title, the programming language used, 
//     your WGU student ID, and your name.

    cout << "Course Title Scripting and Programming - Applications - C867, language used C++, Student ID 001449555, Student Name Aileen Pratt" << std::endl << std::endl;
    
// F2.  Create an instance of the Roster class called classRoster.

    const int numStudents = 5;
    Roster classRoster;

// F3.  Add each student to classRoster.
// F4. Convert the following pseudo code to complete the rest of the  main() function:

    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;

//      classRoster.printAll();

    classRoster.printAll();
    cout << std::endl;

//      classRoster.printInvalidEmails();

    cout << "Displaying invalid emails: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

//      loop through classRosterArray and for each element:
//      classRoster.printAverageDaysInCourse(/*current_object's student id*/);
//      Note: For the current_object's student id, use an accessor (i.e., getter) 
//      for the classRosterArray to access the student id.

    cout << "Displaying average days in course: " << std::endl;
    for (int i = 0; i <= classRoster.getLastStudentIndex(); ++i) {
        string studentID = classRoster.getStudent(i)->getID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << std::endl;

//      classRoster.printByDegreeProgram(SOFTWARE);

    for (int i = 0; i < 3; i++)
    {
        if (i == SOFTWARE)
        {
            cout << "Displaying by degree type: " << degreeProgramOutput[i] << std::endl;
            classRoster.printByDegreeProgram((DegreeProgram)i);
        }
    }

//      classRoster.remove("A3");
//      classRoster.printAll();

    // I built in print all into the remove function, in order to print out the current roster after remove.
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

//      classRoster.remove("A3");
//      expected: the above line should print a message saying such a student with this ID was not found.

    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
// This functionality was not requested in main, it is extra on my part.

    cout << "Displaying students with invalid IDs: " << std::endl;
    classRoster.printInvalidIDs();
    cout << std::endl;

    system("pause");
    return 0;
};