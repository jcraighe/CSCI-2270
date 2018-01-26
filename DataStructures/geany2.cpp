#include <iostream> 
using namespace std;

void multiplyByTwo(int* a, int* b);

int main()
{
	int x = 5;
	int y = 6;
	
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;
	
	multiplyByTwo(&x, &y);
	
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;
	
	return 0;
}

void multiplyByTwo(int* a, int* b)
{
	(*a) = (*a) * 2;
	(*b) = (*b) * 2;
	cout << "a= " << a << "(*a)= " << (*a) << endl;
	cout << "b= " << b << "(*b)= " << (*b) << endl;
	
}
