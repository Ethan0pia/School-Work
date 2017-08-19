/*********************************************************************
** Author: Ethan Dunham
** Date: 10/17/16
** Description: This function will create a hailstorm for an inputed
**				integer.
*********************************************************************/

#include<iostream>
//using std::cout;
//using std::cin;
//using std::endl;

int hailstone(int num) 
{
	int count=0;
	for(;(num != 1) && (num != 0); count++) 
	{
		if (num % 2 == 0)//or iseven(num) 
			num = num / 2;
		else 
			num = num * 3 + 1;
	}
	return count;
}

/*
int main() {
	int number;
	cin >> number;
	number = hailstone(number);
	cout << number << endl;
	return 0;
}
*/