#include "HW4-Todo-StackLinkedList.hpp"
#include <iostream>

using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
	stackHead = NULL;
}

TodoStackLinkedList::~TodoStackLinkedList()
{
	while(stackHead != NULL)
	{
		TodoItem* temp = stackHead->next;
		delete stackHead;
		stackHead = temp;
	}
}

bool TodoStackLinkedList::isEmpty()
{
	if(stackHead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TodoStackLinkedList::push(string todoItem)
{
	TodoItem* newNode = new TodoItem;
	newNode->todo = todoItem;
	newNode->next = stackHead;
	stackHead = newNode;
}

void TodoStackLinkedList::pop()
{
	if(isEmpty())
	{
		cout << "empty stack, cant pop" << endl;
	}
	else
	{
		TodoItem* delNode = stackHead;
		stackHead = stackHead->next;
		delete delNode;
	}
}

TodoItem* TodoStackLinkedList::peek()
{
	if(isEmpty())
	{
		cout << " " << endl;
		return stackHead;
	}
	else
	{
		return stackHead;
	}
}
