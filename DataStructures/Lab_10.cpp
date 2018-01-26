#include <iostream>
using namespace std;

class MinHeap
{
	public:
		MinHeap(int capacity);
		~MinHeap();
		void push(int k);
		int pop();
		int peek() { return heap[1]; }
		void printHeap();
	private:
		int* heap; //pointer to array of eleements
		int capacity; //max possible size of min heap
		int currentSize; // current number of elements
		void MinHeapify(int index);
		int parent(int i) { return i/2; } //integer division, parent is always at index divided by 2
		int left(int i) { return (2*i); } //index times 2
		int right(int i) { return (2*i +1); } //(index times 2) + 1
		void swap(int* x, int* y);
};

MinHeap::MinHeap(int cap)
{
	currentSize = 0;
	capacity = cap + 1; //heap[0] will always be empty
	heap = new int[capacity];
}

MinHeap::~MinHeap()
{
	delete [] heap;
}

void MinHeap::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::push(int key)
{
	if(currentSize == capacity)
	{
		cout << "This shit full...YEET!" << endl;
	}
	else
	{
		currentSize++;
		heap[currentSize] = key;
		int currentIndex = currentSize;
		while(currentSize > 1 && heap[currentIndex] < heap[parent(currentIndex)])
		{
			swap(&heap[currentIndex], &heap[parent(currentIndex)]);
			currentIndex = parent(currentIndex);
		}
	}
}

//this assumes that the subtree is already heapified
void MinHeap::MinHeapify(int index)
{
	int indexofSmallestValue = index;
	int indexofLeftChild = left(index);
	int indexofRightChild = right(index);
	if(indexofLeftChild <= currentSize && heap[indexofLeftChild] < heap[indexofSmallestValue])
	{
		indexofSmallestValue = indexofLeftChild;
	}

	if(indexofRightChild <= currentSize && heap[indexofRightChild] < heap[indexofSmallestValue]) // not else if because right child could be smaller 
	{
		indexofSmallestValue = indexofRightChild;
	}

	if(indexofSmallestValue != index)
	{
		swap(&heap[index], &heap[indexofSmallestValue]);
		MinHeapify(indexofSmallestValue);
	}
}

//for now if nothing to remove, return -1
int MinHeap::pop()
{
	if(currentSize == 0)
	{
		cout << "This is not the heap you are looking for" << endl;
		return -1;
	}
	else if(currentSize == 1)
	{
		int poppedVal = heap[currentSize];
		currentSize--;
		return poppedVal;
	}
	else
	{
		int poppedVal = heap[1];
		heap[1] = heap[currentSize];
		currentSize--;
		MinHeapify(1);
		return poppedVal;
	}
}

void MinHeap::printHeap()
{
	cout << "The heap is currently: {";
	for(int i = 1; i <= currentSize; i++)
	{
		cout << heap[i];
		if(i < currentSize)
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;
}



int main()
{
	MinHeap heap(10);
	cout << "Pushing 3" << endl;
	heap.push(3);
	heap.printHeap();
	cout << "Popping: " << heap.pop() << endl;
	heap.printHeap();
	cout << "Pushing 10" << endl;
	heap.push(10);
	heap.printHeap();
	cout << "Pushing 20" << endl;
	heap.push(20);
	heap.printHeap();
	cout << "Pushing 3" << endl;
	heap.push(3);
	heap.printHeap();
	cout << "Peek: " << heap.peek() << endl;

	

	return 0;
}





