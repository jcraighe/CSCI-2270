#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student
{
	//function
	public:
		Student();
		Student(std::string fn, std::string ln, int _age);
		//string getFirstName();
		std::string getLastName();
		//int getAge();
		//void setFirstname(string fn);
		void setLastName(std::string ln);
		//void setAge(int _age);
	
	//instance variables
	private:
		std::string firstName;
		std::string lastName;
		int age;
};
#endif
