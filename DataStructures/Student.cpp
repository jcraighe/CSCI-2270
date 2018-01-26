#include "Student.hpp"
using namespace std;

Student::Student()
{
	firstName = "unknown";
	lastName = "unknown";
	age = 0;
}

Student::Student(string fn, string ln, int _age)
{
	firstName = fn;
	lastName = ln;
	age = _age; 
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string ln)
{
	lastName = ln;
}
