/*********************************************************************
** Program name:Recursive Test
** Author: Ethan Dunham
** Date: 2/12/17
** Description: This program does several things:
**				1. Reverses a string.
**				2. recursively calculates sum of an array.
**				3. Recursively calculate the triangle of number for N.
*********************************************************************/

#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

void reverse(string);
int arraySum(int[], int);
int triangCalc(int);
void menu();
bool cinFail();

//main function starts the program by calling menu
int main()
{
	menu();
	return 0;
}

//menu forms the backbone of the program, asking for information and executing the orders by calling functions.
void menu()
{
	char strToReverse[100] = {};
	int arrySize=0;
	int *arrayToSum;
	int *oldArray;
	int exit = 0;
	int numToTriangle;
	int option;
	int cont = 0;
	int triang;
	int sum;
	int numToAdd;
	string reversed;
	int i = 0;
	string endArry;
	string str1;
	bool add = false;

	while (exit == 0)//loops while user has not picked exit
	{
		do {//all do loops are validation of cin.fail()
			cout << std::string(2, '\n');
			cout << "Option 1: Reverse a string." << endl;
			cout << "Option 2: Sum an array." << endl;
			cout << "Option 3: Triangle a number." << endl;
			cout << "Option 4: Exit." << endl;
			cin >> option;
		} while (cinFail());

		switch (option)
		{
		case 1://Reverse a string
				cout << std::string(5, '\n');
				do
				{
					cout << "Enter the string you would like to reverse. Max of 100 characters." << endl;
					std::cin.clear();
					std::cin.ignore(300, '\n');
					cin.getline(strToReverse, 100);
				} while (cinFail());
				reverse(strToReverse);
			cout << std::string(2, '\n');
			break;

		case 2://sum an array
			cout << std::string(5, '\n');
			do {
				do {
					cout << std::string(1, '\n');
					cout << "Enter the integer you want to place in the " << i + 1 << " spot of the array. Enter \'A\' to stop entering numbers." << endl;
					cin >> endArry;
					add = false;
					for (int i = 0; i < endArry.length(); i++)
					{
						if (isdigit(endArry[i]))
						{
							add = true;
						}
					}
					if (add)
					{
						numToAdd = stoi(endArry);
					}
				} while (cinFail());
				if (add)
				{
					i++;
				}
				if (arrySize == 0 && add)
				{
					arrySize++;
					arrayToSum = new int[arrySize];
					oldArray = new int[arrySize];
					arrayToSum[0] = numToAdd;
					oldArray[0] = numToAdd;
				}
				else if (add)
				{
					arrySize++;
					delete[] arrayToSum;
					arrayToSum = new int[arrySize];
					for (int i = 0; i < arrySize - 1; i++)
					{
						arrayToSum[i] = oldArray[i];
					}
					arrayToSum[arrySize - 1] = numToAdd;
					delete[] oldArray;
					oldArray = new int[arrySize];
					for (int i = 0; i < arrySize; i++)
					{
						oldArray[i] = arrayToSum[i];
					}
				}
			} while (endArry != "A");
			
			sum = arraySum(arrayToSum, arrySize);
			cout << "The sum of the array is: " << sum << endl;
			delete[] arrayToSum;
			delete[] oldArray;

			break;

		case 3://Triangle a number.
				cout << std::string(5, '\n');
				do {
					cout << "Enter an integer you wish to triangle." << endl;
					std::cin.clear();
					std::cin.ignore(300, '\n');
					cin >> numToTriangle;
				} while (cinFail());
				triang = triangCalc(numToTriangle);
				cout << "The triangle of that number is: " << triang << endl;
				break;

		case 4://exit
			exit++;
		}
	}
}

//Stops endless loops from user entering incorrect information that breaks the program.
bool cinFail()
{
	bool state;//validates cin statements
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(300, '\n');
		state = true;
	}
	else
	{
		state = false;
	}
	return state;
}

/*
1. Write a function that recursively reverses a string. The function will have a single parameter of type string. 
It will print the reversed characters to the screen followed by a newline character. Before you start writing code, 
try to answer these questions to yourself. What is the base case? Will you print out the characters before or after 
the recursive function call? You can try it in both ways and see if it makes a difference and choose one way to use 
in the function.
*/
void reverse(string toReverse)
{
	if (toReverse.length() > 0) 
	{
		int character = toReverse.length()-1;
		char *str;
		str = new char[character+1];
		cout << toReverse[toReverse.length() - 1];
		for (int i = 0; i < character; i++)
		{
			str[i] = toReverse[i];
		}
		str[character] = '\0';
		reverse(str);
		delete[] str;

	}
	else
	{
		cout << endl;
	}
}

/*
2. Write a function that recursively calculates the sum of an array. The function should have 2 parameters, the array 
and an integer showing the number of elements (assume they are all integers) in the array. The function will use a recursive 
call to sum the value of all elements.
*/

int arraySum(int arry[], int size)
{
	int sumOfArray = 0;
	if (size > 0)
	{
		sumOfArray += arry[size - 1];
		sumOfArray += arraySum(arry, size - 1);
		return sumOfArray;
	}
	else
	{
		return 0;
	}
}


/*
3. Write a recursive function to calculate the triangular number for N. (Or a function that counts the number of pins necessary 
for a triangular of N rows.) A triangular number is the sum of all items that form a triangle with N rows. It may help to think 
of the number of bowling pins if you changed the number of rows.  For example, when N=0, the triangular number is 0; When N=1, 
the triangular number is 1; When N=2, the triangular number is 1+2=3; When N=3, the triangular number is 1+2+3=6, so on so forth.
*/

int triangCalc(int N)
{
	int triang = 0;
	if (N > 0)
	{
		triang += N;
		triang += triangCalc(N - 1);
		return triang;
	}
	return 0;
}