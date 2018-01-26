#include <iostream>
using namespace std;


struct WeatherData
{
	double temp;
	double humidity;
	string description;
	string city;
	
};

int main( )
{
	WeatherData newYork;
	newYork.temp = 89;
	newYork.humidity = 45;
	
	WeatherData denver;
	denver.temp = 76;
	denver.humidity = 22;
	
	cout << denver.temp << endl;
	
	return 0;
}
