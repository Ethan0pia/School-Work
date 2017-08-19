/*********************************************************************
** Author: Ethan Dunham
** Date: 9/29/16
** Description: This program finds the Fahrenheir equivalent of a celcius input.
*********************************************************************/

# include <iostream>
# include <string>
using namespace std;


int main()
{
	float celcius, fahrenheit;
	cout << "Please enter a Celcius temperature." << endl;
	cin >> celcius;
	cout << "The equivalent Fahrenheit temperature is :" << endl;
	fahrenheit = 9.0/5*celcius+32;//equation to convert C to F.
	cout << fahrenheit << endl;

	return 0;
}