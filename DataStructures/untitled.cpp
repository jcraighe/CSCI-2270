#include <iostream>

#include <sstream>

#include <fstream>

#include <string>

#include <vector>

using namespace std;

struct list{

string username;

float gpa;

int age;

};

void addUser(vector<list>*,string,float, int );

void printList(const vector<list>);

int main(int argc,char* argv[])

{

vector<list> gradeList;//store lists

string line,username,word;

float gpa;

int age;

//if file name not provided

if(argc!=2){

cout<<"Usage:"<<argv[0]<<" [filename]"<<endl;

return 1;

}

//open file

ifstream infile( argv[1]);

  

if (infile)

{

//get each line

while (getline( infile, line ))

{

istringstream iss(line);

iss>>username;

iss>>word;

gpa=stof(word);

iss>>word;

age=stoi(word);

//pass to addUser

addUser(&gradeList,username,gpa,age);

}

infile.close();

}

else cout << "cannot open file\n";

//print vector

printList(gradeList);

return 0;

}

void addUser(vector<list> *gradeList,string username ,float gpa , int age){

//create a list

struct list record;

record.username=username;

record.gpa=gpa;

record.age=age;

//add list to vector

gradeList->push_back(record);

}

void printList(const vector<list> gradeList){

//iterate through vector and print

for(int i=0;i<gradeList.size();i++){

cout<<gradeList[i].username<<" ["<<gradeList[i].gpa<<"] age:"<<gradeList[i].age<<endl;

}

}
