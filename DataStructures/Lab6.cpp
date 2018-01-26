#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class StackLL
{
public:
	StackLL();
	StackLL(int);
	~StackLL();
	void push(int);
	void pop(int&);
	int peek();
	void printStack();

private:
	node* top;
	int count;

};

StackLL::StackLL()
{
	top = NULL;
	count = 0;
}

StackLL::StackLL(int elem)
{
	count = 1;
	top = new node;
	top->data = elem;
	top->next = NULL;
	//Could use push method instead
}

StackLL::~StackLL()
{
	while(top != NULL)
	{
		node* temp = top->next;
		delete top;
		top = temp;
	}
	count = 0;
}

void StackLL::push(int elem)
{
	node* newNode = new node;
	newNode->data = elem;
	newNode->next = top;
	top = newNode;
	count ++;
}

void StackLL::pop(int& returnedElem)
{
	if(top == NULL)
	{
		cout << "empty stack, cant pop" << endl;
	}
	else
	{
		returnedElem = top->data;
		node* delNode = top;
		top = top->next;
		delete delNode;
		count--;
	}
}

int StackLL::peek()
{
	return top->data;
}

void StackLL::printStack()
{
	if(top == NULL)
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		node* currentNode = top;
		while(currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}





class QueueLL
{
public:
	QueueLL();
	QueueLL(int);
	~QueueLL();
	void enqueue(int);
	void dequeue(int&);
	int peek();
	void printQueue();

private:
	node* top;
	node* bottom;
	int count;

};

QueueLL::QueueLL()
{
	top = NULL;
	bottom = NULL;
	count = 0;
}

QueueLL::QueueLL(int elem)
{
	count = 1;
	top = new node;
	top->data = elem;
	top->next = NULL;
	bottom = top;
	//Could use push method instead
}

QueueLL::~QueueLL()
{
	while(top != NULL)
	{
		node* temp = top->next;
		delete top;
		top = temp;
	}
	delete bottom;
	count = 0;
}

void QueueLL::enqueue(int elem)
{
	node* newNode = new node;
	newNode->data = elem;
	newNode->next = NULL;

	if(count == 0)
	{
		top = newNode;
		bottom = newNode;
	}
	else
	{
		bottom->next = newNode;
		bottom = newNode;
	}

	count ++;
}

void QueueLL::dequeue(int& returnedElem)
{
	if(top == NULL)
	{
		cout << "empty queue, cant dequeue" << endl;
	}
	else
	{
		returnedElem = top->data;
		node* delNode = top;
		top = top->next;
		delete delNode;
		count--;
		if(count == 0)
		{
			bottom = NULL;
		}
	}
}

int QueueLL::peek()
{
	return top->data;
}

void QueueLL::printQueue()
{
	if(top == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		node* currentNode = top;
		while(currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}




int main(int argc, char* argv[])
{
	StackLL firstStack;
	StackLL* secondStack = new StackLL();
	int poppedVal, poppedVal12;
	firstStack.printStack();
	firstStack.push(5);
	firstStack.push(7);
	firstStack.push(4);
	firstStack.printStack();
	firstStack.pop(poppedVal);
	firstStack.printStack();
	
	return 0;
}