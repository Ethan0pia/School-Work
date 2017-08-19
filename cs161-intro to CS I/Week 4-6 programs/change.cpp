/*********************************************************************
** Author: Ethan Dunham
** Date: 9/29/16
** Description: This program will output the smallest number of 
**				coins you can have for an inputted amount of cents.
*********************************************************************/

# include <iostream>
# include <string>
using namespace std;

int main()
{
	int change, quarters, dimes, nickels, pennies; //just int because there are no fraction of cents.
	cout << "Please enter an amount in cents less than a dollar." << endl;
	cin >> change;
	quarters = change / 25;
	dimes = change % 25 / 10;
	nickels = change % 25 % 10 / 5;
	pennies = change % 25 % 10 % 5;

	cout << "Your change will be:" << endl;
	cout << "Q: " << quarters << endl;
	cout << "D: " << dimes << endl;
	cout << "N: " << nickels << endl;
	cout << "P: " << pennies << endl;

	return 0;
}