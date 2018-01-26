#include "HW4-Todo-QueueArray.hpp"
#include <iostream>

using namespace std;

TodoQueueArray::TodoQueueArray()
{
	queueFront = -1;
	queueEnd = -1;

}

bool TodoQueueArray::isEmpty()
{
	if(queueFront == -1)
	{
		return true;
	}
	return false;
	
}

bool TodoQueueArray::isFull()
{
	if(queueEnd == MAX_QUEUE_SIZE-1)
	{
		return true;
	}
	return false;
}

void TodoQueueArray::enqueue(string todoItem)
{
	if(isFull())
	{
		cout << "Queue full, cannot add new todo item. " << endl;
		return;
		
	}
	else
	{
		if(isEmpty())
		{

			queueFront = 0;
		}
		queueEnd++;
		TodoItem* temp = new TodoItem;
		temp->todo = todoItem;
		queue[queueEnd] = temp;
		
	}
}

void TodoQueueArray::dequeue()
{
	if(isEmpty())
	{
		cout << "Queue empty, cannot dequeue an item. " << endl;
		return;
	}
    else if(queueFront == queueEnd)
	{
		queueFront = -1;
		queueEnd = -1;
	}
	else
	{
		for(int i = 0; i < queueEnd; i++)
		{
		    queue[i] = queue[i+1];
		}
		queueEnd--;
	}

}

TodoItem* TodoQueueArray::peek()
{
	if(isEmpty())
	{
		//cout << "Queue empty, cannot peek. " << endl;
		return queue[queueFront];
	}
	else
	{
		//cout << queue[queueFront]->todo << endl;
		return queue[queueFront];
	}

}

