/*********************************************************************
** Author: Ethan Dunham
** Date: 10/17/16
** Description: This function will take 3 integers and organize them
**				from smallest to largest.
*********************************************************************/

#include<iostream>
//using std::cout;
//using std::endl;
//using std::cin;

void smallSort2(int *num1, int *num2, int *num3) 
{
	int small, medium, large;
	small = medium = large = *num1;
	if (*num2 <= *num1 && *num2 <= *num3)
		small = *num2;
	if (*num3 <= *num1 && *num3 <= *num2)
		small = *num3;
	if (*num2 >= *num1 && *num2 >= *num3)
		large = *num2;
	if (*num3 >= *num1 && *num3 >= *num2)
		large = *num3;
	if ((small == *num2 || small == *num3) && (large == *num2 || large == *num3))
		medium = *num1;
	if ((small == *num1 || small == *num3) && (large == *num1|| large == *num3))
		medium = *num2;
	if ((small == *num1 || small == *num2) && (large == *num1 || large == *num2))
		medium = *num3;
	*num1 = small;
	*num2 = medium;
	*num3 = large;
}

/*
#include<iostream>
using namespace std;
int main() {
	int a = 20;
	int b = 12;
	int c = -12;
	smallSort2(&a, &b, &c);
	cout << a << ", " << b << ", " << c << endl;
	return 0;
}
*/