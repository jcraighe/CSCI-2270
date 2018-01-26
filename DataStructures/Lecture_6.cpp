#include <iostream>
using namespace std;

int myMethod(int x);

int main()
{
	cout << myMethod(2) << endl;
	
	return 0;
}


//recurssion is when you call a method over and over again
int myMethod(int x)
{
	int y;
	if( x == 0 )
		return 1;
	else
	{
		y = 2 * myMethod(x-1);  // 3*2*1
		return y+1; //6 + 1 
		
	}
}


