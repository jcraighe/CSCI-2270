#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int insertIntoSortedArray(int myArray[ ], int numEntries, int newValue);
void displayArray(int myArray[], int numValue);

int main(int argc, char* argv[])
{
	int ENTRIES = 0;	//constant for the size of array 
	
	int myArray[100];
	
	for (int i = 0; i < 100; i++) // ...initialize it
	{
		myArray[i] = 0;
	}	
	
	ifstream inFile;
	string data;
	inFile.open(argv[1]); //open the file
	if(inFile.is_open())
	{ //error check
		cout << argv[1] << endl;
		while(getline(inFile, data))
		
		{ //read/get every line of the file and store it
			
			//cout << data << endl; //can see the data (each line) printed
			stringstream ss(data); //create a stringstream variable from the string data
			
			int elementOne;
			ss >> elementOne;
			ENTRIES = insertIntoSortedArray(myArray, ENTRIES, elementOne);
			
			
			
			displayArray(myArray, ENTRIES);
			
		}
		inFile.close(); //close the file
		cout << ENTRIES << endl;

	}
	else
	{
		cout << "File unsuccessfully opened" << endl;
	}
	
	return 0;
}


int insertIntoSortedArray(int myArray[ ], int numEntries, int newValue)
{
	int _numEntries = numEntries + 1;
	
	
	for(int i = numEntries; i >= 0; i--)
	{
		
		if(myArray[i] > newValue)
		{
			myArray[i + 1] = myArray[i];
			
		}
		else if(myArray[i] > 0 && myArray[i] < newValue)
		{
			continue;
		}
		
		myArray[i] = newValue;	
	} 
	
	return _numEntries;
}



void displayArray(int _myArray[], int numValues)
{
	for(int i = 0; i < numValues; i++)
	{
		if(i < numValues - 1)
		{
			cout << _myArray[i] << ",";
		}
		else
		{
			cout << _myArray[i] << endl;
		}
		
	}

}
