#include <string>
#include <fstream>
#include <iostream>
#include "PRIORITYQUEUE_HPP.hpp"

using namespace std;

	/*
	class constructor
	Purpose: perform all operations necessary to instantiate a class object 
	Parameter _queueSize: Maximum size of the priority queue
	return: none
	*/
	PriorityQueue::PriorityQueue(int _queueSize)
	{
		currentQueueSize = 0;
		maxQueueSize = _queueSize+1;
		priorityQueue = new PatientNode[maxQueueSize];
	}

	/*
	class destructor
	Purpose: free all resources that the object has acquired
	Parameters: none
	return: none
	*/
	PriorityQueue::~PriorityQueue()
	{
		delete [] priorityQueue;
	}

	/*
	Method Name: enqueue
	Purpose: enqueue new patient into priority queue; call other method(s) as required to maintain heap
	Parameter: _name - name of patient to be entered in priority queue
	Parameter: _injurySeverity - severity of injury
	Parameter: _treatmentTime - time required for doctor to treat patient injury
	returns void
	*/
	void PriorityQueue::enqueue (std::string _name, int _injurySeverity, int _treatmentTime)
	{
		currentQueueSize++;
		priorityQueue[currentQueueSize].name = _name;
		priorityQueue[currentQueueSize].injurySeverity = _injurySeverity;
		priorityQueue[currentQueueSize].treatmentTime = _treatmentTime;
		repairUpward(currentQueueSize);
	}

	/*
	Method Name: dequeue
	Purpose: remove the patient at the front of the priority queue from the queue, call other method(s) as required to maintain heap
	Parameters: none
	return: void
	*/
	void PriorityQueue::dequeue()
	{
		priorityQueue[1] = priorityQueue[currentQueueSize];
		currentQueueSize--;
		repairDownward(1);
	}

	/*
	Method Name: peekName
	Purpose: get name of patient at front of priority queue while maintaining encapsulation
	Parameters: none
	return: name of patient at the front of the priority queue
	*/
	std::string PriorityQueue::peekName()
	{
		return priorityQueue[1].name;
	}

	/*
	Method Name: peekInjurySeverity
	Purpose: get injury severity of patient at front of priority queue while maintaining encapsulation
	Parameters: none
	return: injury severity of patient at the front of the priority queue
	*/
	int PriorityQueue::peekInjurySeverity()
	{
		return priorityQueue[1].injurySeverity;
	}

	/*
	Method Name: peekTreatmentTime
	Purpose: get treatment time of patient at front of priority queue while maintaining encapsulation
	Parameters: none
	return: treatment time of patient at the front of the priority queue
	*/
	int PriorityQueue::peekTreatmentTime()
	{
		return priorityQueue[1].treatmentTime;
	}

	/*
	Method Name: isFull
	Purpose: indicate if priority queue is full
	Parameters: none
	return: true if queue is full, false otherwise
	*/
	bool PriorityQueue::isFull()
	{
		if(currentQueueSize == maxQueueSize-1)
		{
			return true;
		}
		return false;
	}

	/*
	Method Name: isEmpty
	Purpose: indicate if priority queue is empty
	Parameters: none
	return: true if queue is empty, false otherwise
	*/
	bool PriorityQueue::isEmpty()
	{
		if(currentQueueSize == 0)
		{
			return true;
		}
		return false;
	}

	/*
	Method Name: repairUpward
	Purpose: maintain heap properties by swapping node with parent if necessary
	Parameter nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void PriorityQueue::repairUpward(int nodeIndex)
	{
		while(nodeIndex > 1 && priorityQueue[nodeIndex].injurySeverity >= priorityQueue[nodeIndex/2].injurySeverity)
		{
			PatientNode temp = priorityQueue[nodeIndex];
			priorityQueue[nodeIndex] = priorityQueue[nodeIndex/2];
			priorityQueue[nodeIndex/2] = temp;
			nodeIndex = nodeIndex/2;
		}
	}

	/*
	Method Name: repairDownward
	Purpose: maintain heap properties by swapping node with child if necessary
	Parameter: nodeIndex - index of node that may violate heap properties
	return: void
	*/
	void PriorityQueue::repairDownward(int nodeIndex)
	{
		int indexofHighestPriority = nodeIndex;
		int indexofLeftChild = 2 * nodeIndex;
		int indexofRightChild = (2 * nodeIndex) + 1;

		if(indexofLeftChild <= currentQueueSize && priorityQueue[indexofLeftChild].injurySeverity > priorityQueue[indexofHighestPriority].injurySeverity)
		{
			indexofHighestPriority = indexofLeftChild;
		}

		if(indexofRightChild <= currentQueueSize && priorityQueue[indexofRightChild].injurySeverity > priorityQueue[indexofHighestPriority].injurySeverity) // not else if because right child could be smaller 
		{
			indexofHighestPriority = indexofRightChild;
		}

		if(indexofHighestPriority != nodeIndex)
		{
			PatientNode temp = priorityQueue[nodeIndex];
			priorityQueue[nodeIndex] = priorityQueue[indexofHighestPriority];
			priorityQueue[indexofHighestPriority] = temp;
			repairDownward(indexofHighestPriority);
		}
	}


int main()
{
	bool endLoop = true;
	PriorityQueue* myQueue = new PriorityQueue(10);

	while(endLoop) //while loop for the menu
	{
		int minput;
		cout << "======Main Menu======" << endl;
		cout << "1. Get Patient Information from File" << endl;
		cout << "2. Add Patient to Priority Queue" << endl;
		cout << "3. Show Next Patient" << endl;
		cout << "4. Treat Next Patient" << endl;
		cout << "5. Treat Entire Queue" << endl;
		cout << "6. Quit" << endl;

		cin >> minput;

        switch(minput)  //  main switch for menu input
        {
            case 1:
               if(myQueue->isFull())
               {
               	cout << "Priority Queue full. Send remaining patients to another hospital." << endl;
               }
               else
               {
               	cout << "Enter filename:" << endl;
				//if priority queue is full, or becomes full during the process of
				//enqueueing all patients in the file, print once regardless of how
				//many patients are turned away
               }
                break;

            case 2:
            	if(myQueue->isFull())
            	{
            		cout << "Priority Queue full. Send Patient to another hospital." << endl;
            	}
            	else
            	{
            		string name;
            		int inj;
            		int tre;
            		cout << "Enter Patient Name:" << endl;
            		cin >> name;
					cout << "Enter Injury Severity:" << endl;
					cin >> inj;
					cout << "Enter Treatment Time:" << endl;
					cin >> tre;
					myQueue->enqueue(name, inj, tre);
           		}
            
                break;

            case 3:
               if(myQueue->isEmpty())
               {
               	cout << "Queue empty." << endl;
               }
               else
               {
               	cout << "Patient Name: " << myQueue->peekName() << endl;
				cout << "Injury Severity: " << myQueue->peekInjurySeverity() << endl;
				cout << "Treatment Time: " << myQueue->peekTreatmentTime() << endl;
               }
                break;

            case 4:
              if(myQueue->isEmpty())
              {
              	cout << "Queue empty." << endl;
              }
              else
              {
              	cout <<"Patient Name: "<< myQueue->peekName() << " - Total Time Treating Patients: " << myQueue->peekTreatmentTime() << endl;
              	myQueue->dequeue();
              }
                break;

            case 5:
             if(myQueue->isEmpty())
             {
             	cout << "Queue empty." << endl;
             }
             else
             {
             	while(!myQueue->isEmpty())
             	{
             		myQueue->dequeue();
             	}
             }
                break;

            case 6:
                cout<<"Goodbye!"<<endl;
                return 0;
                break;

            default:
            endLoop = false;
        }
    }
}





