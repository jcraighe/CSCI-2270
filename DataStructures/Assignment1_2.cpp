#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct list
{
	string username;
	float gpa;
	int age;
};

void addUser(vector<list> *gradeList, string name, float _gpa, int _age);
void printList(const vector<list> gradeList);

int main(int argc, char* argv[])
{
	vector<list> gradeList;
	string username = " ";
	string carrier = " ";
	float gpa = 0.0;
	int age = 0;
	
	
	ifstream inFile;
	string data;
	inFile.open(argv[1]); //open the file
	if(inFile.is_open())
	{ //error check
		
		while(getline(inFile, data))
		
		{ //read/get every line of the file and store it
			
			//cout << data << endl; //can see the data (each line) printed
			stringstream ss(data); //create a stringstream variable from the string data
			
			string elementOne;
			//float elementTwo;
			//int elementThree;
			
			ss >> username;
			
			ss >> carrier;
			gpa = stof(carrier);
			
			ss >> carrier;
			age = stoi(carrier);
			
			addUser(&gradeList,username,gpa,age);
			
			
	
			
		}
		inFile.close(); //close the file

	}
	else
	{
		cout << "File unsuccessfully opened" << endl;
	}
	
	printList(gradeList);
	return 0;
}


void addUser(vector<list> *gradeList, string name, float _gpa, int _age)
{
	struct list user;
	
	user.username = name;
	user.gpa = _gpa;
	user.age = _age;
	
	gradeList->push_back(user);
	
}


void printList(const vector<list> gradeList)
{
	for(int i = 0; i < int(gradeList.size()); i++)
	{
		cout<<gradeList[i].username<<" ["<<gradeList[i].gpa<<"] age:"<<gradeList[i].age<<endl;
	}	
	
}
