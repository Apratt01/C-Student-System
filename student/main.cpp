#include "roster.h"

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

    const int numStudents = 5;
    Roster roster;

    cout << "Course Title Scripting and Programming - Applications - C867, language used C++, Student ID 001449555, Student Name Aileen Pratt" << std::endl << std::endl;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;

    cout << "Displaying invalid emails: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days in course: " << std::endl;
    roster.printAverageDaysInCourse();

    for (int i = 0; i < 3; i++)
    {
        cout << "Displyaing by degree type: " << degreeProgramOutput[i] << std::endl;
        roster.printByDegreeProgram((DegreeProgram)i);
    }

    cout << "Removing student with ID A3:" << std::endl;
    roster.remove("A3");
    cout << std::endl;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;

    cout << "Removing student with ID A3:" << std::endl;
    roster.remove("A3");
    cout << std::endl;
    
    cout << "Displaying students with invalid IDs: " << std::endl;
    roster.printInvalidIDs();
    cout << std::endl;

    system("pause");
    return 0;
}