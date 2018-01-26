#include <iostream>

using namespace std;
//node implementation for doubly linked list
struct Node
{
	int key;
	Node* previous;
	Node* next;
};

Node* insertAtEnd(Node* , int);
void printTailToHead(Node*);

int main(int argc, char* argv[])
{
	Node *head = NULL;
	Node *tail = NULL;
	
	tail = insertAtEnd(tail, 47);
	printTailToHead(tail);
	tail = insertAtEnd(tail, 22);
	printTailToHead(tail);
	tail = insertAtEnd(tail, 999);
	printTailToHead(tail);
	return 0;
}

Node* insertAtEnd(Node *tail, int val)
{
	if(tail == NULL)
	{
		//nothing in list
		tail = new Node;
		tail->key = val;
		tail->next = NULL;
		tail->previous = NULL;
	}
	else
	{
		//element(s) in list
		Node *newNode = new Node;
		newNode->key = val;
		newNode->next = NULL;
		newNode->previous = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return tail;
}

void printTailToHead(Node *tail)
{
	//use " <-> " between nodes
	//traverse backwards from tail
	Node *curPtr = tail;
	if(curPtr == NULL)
	{
		cout << "nothing to see here" << endl;
	}
	else
	{
		cout << "NULL";
		while(curPtr != NULL)
		{
			cout << " <-> " << curPtr->key;
			curPtr = curPtr->previous;
		}
		cout << " <-> NULL " << endl;
	}
}
