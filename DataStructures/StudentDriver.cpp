#include <iostream> 
//other libraries like fstream
#include "Student.hpp"
using namespace std;

/*
class Student
{
	//function
	public:
		Student();
		Student(string fn, string ln, int _age);
		//string getFirstName();
		string getLastName();
		//int getAge();
		//void setFirstname(string fn);
		void setLastName(string ln);
		//void setAge(int _age);
	
	//instance variables
	private:
		string firstName;
		string lastName;
		int age;
};
*/

int main()
{
	Student liz = Student();
	cout << liz.getLastName() << endl;
	Student elle = Student("Elle", "Boese", 28);
	cout << elle.getLastName() << endl;
	
	return 0;
}

/*
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
*/
