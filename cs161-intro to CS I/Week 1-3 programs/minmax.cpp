/****************************
**Author:Ethan Dunham
**Date:10/08/16
**Description:This program finds the min and max numbers of some numbers.
********************************/

#include <iostream>
using namespace std;

main() {
	int numOfLoops = 0; //keeps track of how many loops have happened.
	int numOfNums, numberInput, highNum, lowNum;

	cout << "How many integers would you like to enter?" << endl;
	cin >> numOfNums;

	while (numOfNums<1) //verifies user input is not negative or 0.
	{
		cout << "Please enter a positive integer.\n" 
			<< "How many integers would you like to enter?" << endl;
		cin >> numOfNums;
	}

	cout << "Please enter " << numOfNums << " integers." << endl;//asks for X numbers.
	cin >> numberInput;
	lowNum = highNum = numberInput;//puts first number as both low and high.

	while ((numOfNums - 1) != numOfLoops)//determins high and low for all the rest of the numbers.
	{
		cin >> numberInput;
		if (numberInput > highNum)//determines if new number is higher than the previous high.
			highNum = numberInput;
		if (numberInput < lowNum)//determines of new number is lower than previous low.
			lowNum = numberInput;
		numOfLoops++;//adds 1 to loop to eventually close loop.
	}
	
	cout << "min: " << lowNum << endl;//displays the low of all the numbers.
	cout << "max: " << highNum << endl;//displays the high of all the numbers.

	return 0;
}