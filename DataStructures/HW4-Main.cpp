#include <iostream>
//#include "HW4-Todo-QueueArray.cpp"
//#include "HW4-Todo-QueueLinkedList.cpp"
#include "HW4-Todo-StackArray.cpp"

using namespace std;

int main()
{
	/*
	TodoQueueArray test1;
	cout << test1.getQueueFront() << endl;
	cout << test1.getQueueEnd()<< endl;
	test1.dequeue();
	test1.peek();
	if(test1.isEmpty())
	{
		cout << "Test 1 is empty " << endl;
	}
	test1.enqueue("Take out the garbage");
	test1.enqueue("sit");
	cout << test1.getQueueFront() << endl;
	cout << test1.getQueueEnd()<< endl;
	test1.peek();
	test1.dequeue();
	test1.peek();
*/

	/*TodoQueueLinkedList test2;
	test2.getQueueFront();
	test2.getQueueEnd();
	test2.enqueue("do hw");
	test2.peek();
	test2.dequeue();
	test2.dequeue();
*/

	TodoStackArray test3;
	test3.getStackTop();
	test3.push("HW");
	test3.push("do trash");
	test3.peek();
	test3.pop();
	//test3.pop();
	test3.peek();


	return 0;
}