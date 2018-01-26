//pointers

#include <iostream>


using namespace std;

int main()
{
	int a = 123
	int *p;
	p = &a;
	
	cout << *p << endl;
	
	*p=3
	
	cout << *p << endl;
	
	swap(&x, &y);
	
	return 0;
}


// Swap by reference 

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
