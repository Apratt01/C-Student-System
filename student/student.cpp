#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string fristName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->emailAddress = email; }
void Student::setAge() { this->age = age; }
void Student::setDays(int days[])
{
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }

void Student::printHeader()
{
	cout << "Output format: ID | First Name | Last Name | Age | Days In Course | Degree Program\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	//cout << this->getEmail() << '\t';
	cout << "daysInCourse: {" << this->getDays()[0] << ', ';
	cout << this->getDays()[1] << ', ';
	cout << this->getDays()[2] << '}' << '\t';
	cout << "Degree Program: " << degreeProgramOutput[this->getDegreeProgram()] << '\n';
}