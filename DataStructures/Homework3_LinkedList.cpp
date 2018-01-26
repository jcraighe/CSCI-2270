// ==========================================
// File: Assignment 3 starter code
// Author: Chase Dudas
// Date: 10/8/2017
// Modified: Fall 2016 E.S.Boese
// Fall 2017 W.Temple
// Description: Linked List Fun
// ==========================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


// DO NOT MODIFY THIS STRUCT
struct city
{
	string name; // name of the city
	city *next; // pointer to the next city
	int numberMessages; // how many messages passed through this city
	string message; // message we are sending accross
};



/* Function prototypes */
city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string filename);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);


/* Do NOT modify main function */
int main(int argc, char* argv[])
{
	// pointer to the head of our network of cities
	city *head = NULL;

	head = handleUserInput(head);
	printPath(head);
	head = deleteEntireNetwork(head);
	if (head == NULL)
	cout << "Path cleaned" << endl;
	else
	printPath(head);
	cout << "Goodbye!" << endl;
	return 0;
}


/*
* Purpose: handle the interaction with the user
* @param head the start of the linked list
* @return the start of the linked list
*
* DO NOT MODIFY THIS FUNCTION
*/
city* handleUserInput(city *head)
{
	bool quit = false;
	string s_input;
	int input;
	// loop until the user quits
	while (!quit)
	{
		displayMenu();
		// read in input, assuming a number comes in
		getline(cin, s_input);
		input = stoi(s_input);
		switch (input)
		{
			// print all nodes
			case 1: //rebuild network
			head = loadDefaultSetup(head);
			printPath(head);
			break;
			case 2: // print path
			printPath(head);
			break;
			case 3: //message is read in from file

			{

			string cityReceiver;

			cout << "Enter name of the city to receive the message: " << endl;
			getline(cin, cityReceiver);
			cout << "Enter the message to send: " << endl;
			string message;
			getline(cin, message);

			transmitMsg(head, cityReceiver, message);

			}
			break;
			case 4:
			{

				string newCityName;
				string prevCityName;
				cout << "Enter a new city name: " << endl;
				getline(cin, newCityName);
				cout << "Enter the previous city name (or First): " << endl;
				getline(cin, prevCityName);
				// find the node containing prevCity
				city *tmp = NULL;
				if(prevCityName !="First")
				tmp = searchNetwork(head, prevCityName);
				// add the new node
				head = addCity(head, tmp, newCityName);
				printPath(head);

			}
			break;
			case 5: // delete city

			{

				string city;
				cout << "Enter a city name: " << endl;
				getline(cin, city);
				head = deleteCity(head, city);
				printPath(head);

			}
			break;
			case 6: // delete network
			head = deleteEntireNetwork(head);
			break;
			case 7: // quit

			quit = true;

			cout << "Quitting... cleaning up path: " << endl;

			break;
			default: // invalid input
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return head;
}


/*
* Purpose: Add a new city to the network
* between the city *previous and the city that follows it in the network.
* Prints: `prev: <city name> new: <city name>` when a city is added,
* prints _nothing_ if the city is being added to the _first_ position in
* the list.
* @param head pointer to start of the list
* @param previous name of the city that comes before the new city
* @param cityName name of the new city
* @return pointer to first node in list
*/
city* addCity(city *head, city *previous, string cityName )
{
	if (head == NULL)
    {
        head = new city;
        head->name = cityName;
        return head;
    }

    city *newNode = new city;
    newNode->name = cityName;

    if (previous == NULL)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    newNode->next = previous->next;
    previous->next = newNode;

    cout << "prev: " << previous->name << "  new: " << cityName << endl;

    return head;
}



/*
* Purpose: Search the network for the specified city and return a pointer
* to that node
* @param ptr head of the list
* @param cityName name of the city to look for in network
* @return pointer to node of cityName, or NULL if not found
* @see addCity, deleteCity
*/
city *searchNetwork(city *ptr, string cityName)
{
	city* tempCity = ptr;
	while(tempCity != NULL)
	{
		if(tempCity->name == cityName)
		{
			return tempCity;
		}
		tempCity = tempCity->next;
	}

	return NULL;
}



/*
* Purpose: deletes all cities in the network starting at the head city.

* @param ptr head of list
* @return NULL as the list is empty
*/
city* deleteEntireNetwork(city *ptr)
{
	if(ptr == NULL)
	{
		return ptr;
	}
	else
	{
		while(ptr != NULL)
		{
			city* tempCity = ptr->next;

			cout << "deleting: " << ptr->name << endl;
			delete ptr;

			ptr = tempCity;
		
		}
		delete ptr;
		cout << "Deleted network" << endl;
		ptr = NULL;
		// return head, which should be NULL
		return ptr;
	}
}




/*
* Purpose: transmit a message from city to city
* @param head pointer to head of the list
* @param receiver the name of the City to receive the message
* @param message the message to transmit*/
void transmitMsg(city *head, string receiver, string message)
{
	city* sender = head;

	if(head == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		while(sender != NULL)
		{
			sender->numberMessages = sender->numberMessages + 1;
			sender->message = message;
			cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;

			if(sender->name == receiver)
			{
				return;
			}
			else 
			{
				sender = sender->next;
			}


		}


	}


}



/*
* Purpose: delete the city in the network with the specified name.
* @param head first node in list
* @param cityName name of the city to delete in the network
* @return head node of list
*/
city* deleteCity(city *head, string cityName)
{
	city *temp = new city; 
    city *prev = new city; 
    temp = head;
    if(cityName == head->name)
    {
       temp = head->next;
       delete head;
       head = temp;
       return head;
    }
    while(temp != NULL && temp->name != cityName)
    {
       prev = temp;
       temp = temp->next;
    }
    if(temp == NULL)
    {
        cout << "City does not exist." << endl;
    }
    else
    {
       prev->next = temp->next; //changes the previous next pointer to skip the deleted node
       delete temp;
    }


    return head;
}




/*
* Purpose: prints the current list nicely
* @param ptr head of list
*/
void printPath(city *ptr)
{
	cout << "== CURRENT PATH ==" << endl;
	// If the head is NULL
	if (ptr == NULL)
	cout << "nothing in path" << endl;
	// Add code here to print the network path.
	else
	{
        city *temp2 = ptr;
        while( temp2!=NULL )
        {
         	cout << temp2->name << " -> ";// show the data in the linked list
         	temp2 = temp2->next;   // tranfer the address of 'temp->next' to 'temp'
        }
        cout << " NULL" << endl;
    }
  
    cout << "===" << endl;
}


/*
* Purpose: populates the network with the predetermined cities
* @param head start of list
* @return head of list
*/
city* loadDefaultSetup(city *head)
{
//default network setup by adding all the cities after each other with tmp being the tail
    head = addCity(head,NULL,"Los Angeles");
   city *tmp = new city;
   tmp = head;
   addCity(head,tmp,"Phoenix");
   tmp = tmp->next;
   addCity(head,tmp,"Denver");
   tmp = tmp->next;
   addCity(head,tmp,"Dallas");
   tmp = tmp->next;
   addCity(head,tmp,"Atlanta");
   tmp = tmp->next;
   addCity(head,tmp,"New York");
    return head;
}



/* Purpose: displays a menu with options
* DO NOT MODIFY THIS FUNCTION
*/

void displayMenu()
{
cout << "Select a numerical option:" << endl;
cout << "======Main Menu=====" << endl;
cout << "1. Build Network" << endl;
cout << "2. Print Network Path" << endl;
cout << "3. Transmit Message" << endl;
cout << "4. Add City" << endl;
cout << "5. Delete City" << endl;
cout << "6. Clear Network" << endl;
cout << "7. Quit" << endl;
}
