/*********************************************************************
** Author: Ethan Dunham
** Date: 9/29/16
** Description: This program will find the average of five numbers.
*********************************************************************/

# include <iostream>
# include <string>
using namespace std;

//A program to find averages of 5 numbers.
int main()
{
	//Used long double incase people want to put in some crazy numbers.
	long double number1, number2, number3, number4, number5, average;
	cout << "Please enter five numbers." << endl;
	cin >> number1 >> number2 >> number3 >> number4 >> number5;
	cout << "The average of those numbers is:" << endl;
	average = (number1 + number2 + number3 + number4 + number5) / 5;
	cout << average << endl;

	return 0;
}