#include <iostream>
using namespace std;

struct Node
{
	int data;	
};

const int MAX_SIZE = 5;

class QueueArr
{
	public:
		QueueArr();
		bool isEmpty();
		bool isFull();
		bool enqueue(int value);
		bool dequeue();
		int peek();

	private:
		int frontIndex;
		int backIndex;
		Node myArray[MAX_SIZE];

};


QueueArr::QueueArr()
{
	frontIndex = -1;
	backIndex = -1;
}

bool QueueArr::isEmpty()
{
	if(frontIndex = -1)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool QueueArr::isFull()
{

	//do the ting
}

bool QueueArr::enqueue(int value)
{
	if(isFull())
	{
		//error
		return false;
	}
	else if(isEmpty())
	{
		frontIndex = 0;
		backIndex = 0;
		myArray[backIndex].data = value;
	}
	else
	{
		backIndex++;
		if(backIndex > MAX_SIZE - 1)
		{
			backIndex = 0;
		}
		myArray[backIndex].data = value;
	}
	return true;
}

bool QueueArr::dequeue()
{
	if(isEmpty())
	{
		//error
		return false;
	}

	frontIndex++;
	if(frontIndex > MAX_SIZE-1)
	{
		frontIndex = 0;
	}
	return true;
}

int main()
{

	
	return 0;
}