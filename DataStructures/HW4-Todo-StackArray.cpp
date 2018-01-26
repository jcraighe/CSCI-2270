#include "HW4-Todo-StackArray.hpp"
#include <iostream>

using namespace std;

TodoStackArray::TodoStackArray()
{
	stackTop = -1;
}

bool TodoStackArray::isEmpty()
{
	if(stackTop == -1)
	{
		return true;
	}
	return false;
}

bool TodoStackArray::isFull()
{
	if(stackTop == MAX_STACK_SIZE-1)
	{
		return true;
	}
	return false;
}

void TodoStackArray::push(string todoItem)
{
	if(isFull())
	{
		cout << "Stack full, cannot add new todo item. " << endl;
		return;
	}
	TodoItem* temp = new TodoItem;
	temp->todo = todoItem;
	stack[++stackTop] = temp;
}

void TodoStackArray::pop()
{
	
	if(isEmpty())
	{
		cout << "Stack empty, cannot pop an item. " << endl;
		
	}
	else
	{
		TodoItem* delNode = new TodoItem;
		delNode = stack[stackTop];
		delete delNode;
		stackTop--;
	}

}

TodoItem* TodoStackArray::peek()
{
	if(isEmpty())
	{
		cout << "Stack empty, cannot peek. ";
		
	}
	cout << stack[stackTop]->todo << endl;
	return stack[stackTop];
}

