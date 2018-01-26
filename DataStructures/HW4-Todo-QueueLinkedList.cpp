#include "HW4-Todo-QueueLinkedList.hpp"
#include <iostream>

using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList()
{
	queueFront = NULL;
	queueEnd = NULL;
}

TodoQueueLinkedList::~TodoQueueLinkedList()
{
	while(queueFront != NULL)
	{
		TodoItem* temp = queueFront->next;
		delete queueFront;
		queueFront = temp;
	}
	delete queueEnd;
}

bool TodoQueueLinkedList::isEmpty()
{
	if(queueFront == NULL)
	{
		return true;
	}
	return false;
}

void TodoQueueLinkedList::enqueue(string todoItem)
{
	TodoItem* newNode = new TodoItem;
	newNode->todo = todoItem;
	newNode->next = NULL;

	if(isEmpty())
	{
		queueFront = newNode;
		queueEnd = newNode;
	}
	else
	{
		queueEnd->next = newNode;
		queueEnd = newNode;
	}
}

void TodoQueueLinkedList::dequeue()
{
	if(isEmpty())
	{
		cout << "Queue empty, cannot dequeue an item. " << endl;
	}
	else
	{
		TodoItem* delNode = queueFront;
		queueFront = queueFront->next;
		delete delNode;
		if(queueFront == NULL)
		{
			queueEnd = NULL;
		}
	}
}

TodoItem* TodoQueueLinkedList::peek()
{
	if(queueFront == NULL)
	{
		cout << "Queue empty, cannot peek. " << endl;
		return queueFront;
	}
	else
	{
		cout << queueFront->todo << endl;
		return queueFront;
	}
}