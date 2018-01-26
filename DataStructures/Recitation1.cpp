#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//Creating	a	struct	data	type:	a	template	to	define	all	instances
struct CarData
{
 string model;
 string make;
 string year;
};


int main(int argc, char* argv[])
{
	CarData car; //Create an instance of CarData called car
	
	CarData carArray[10];	//Create an array of CarData
	

	ifstream inFile;
	string data;
	inFile.open(argv[1]); //open the file
	if(inFile.is_open())
	{ 
		//cout << "opened successfully" << endl;
		int counter = 0;	//to assign/loop car to the array
		while(getline(inFile, data))
			{						 
				stringstream ss(data); 
				
				string elementOne;
				string elementTwo;
				string elementThree;
				
				ss >> elementTwo;
				//cout << elementTwo << endl;
				car.make = elementTwo;
				
				ss >> elementThree;
				//cout << elementThree << endl;
				car.model = elementThree;

				ss >> elementOne;
				//cout << elementOne << endl;
				car.year = elementOne;
				
				carArray[counter] = car;
				
				counter++;
			}
		inFile.close(); //close	the	file
	
	}
	else
	{
		cout << "File unsuccessfully opened" << endl;
	}
	
	for(int i = 0; i < 10; i++) //print the array of CarData
	{
		cout << "make:" << carArray[i].make << " model:" << carArray[i].model << " year:" << carArray[i].year << endl;
	}
	
	return 0;
}
