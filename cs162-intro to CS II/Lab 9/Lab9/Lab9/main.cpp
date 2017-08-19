/**********************************************************************
** Program name:Palindrome and Queue
** Author: Ethan Dunham
** Date: 3/8/17
** Description: This program demonstrates the understanding of STL.
**********************************************************************/

#include<string>
#include<iostream>
#include<vector>
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include "Stack.hpp"
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;



string palindrome(string);
void queue(int, int, int);
int random(int);
bool cinFail();

int main()
{
	bool exit = false;
	srand(time(NULL));
	string str;
	int outPercent, inPercent, turns;
	while (!exit)
	{
		int option;
		do {
			cout << "Option 1: Create a queue." << endl;
			cout << "Option 2: Create a palindrome." << endl;
			cout << "Option 3: Quit." << endl;
			cin >> option;
		} while (cinFail() || option < 0 || option>3);

		switch (option)
		{
		case 1:
			do {
				cout << "Enter the number of turns you wish the queue to run for." << endl;
				cin >> turns;
			} while (cinFail() || turns < 0);

			do {
				cout << "Enter the percentage chance of an item being removed from the queue." << endl;
				cin >> outPercent;
			} while (cinFail() || outPercent < 0 || outPercent>100);

			do {
				cout << "Enter the percentage chance of an item being added to the queue." << endl;
				cin >> inPercent;
			} while (cinFail() || inPercent < 0 || inPercent>100);
			queue(turns, outPercent, inPercent);
			break;

		case 2:
			do {
				cout << "Enter the string you wish to get the palindrome for." << endl;
				cin >> str;
			} while (cinFail());
			str = palindrome(str);
			cout << str << endl;
			break;

		case 3:
			exit = true;
		}
	}
	return 0;
}

//returns palindrome by pushing each letter to a vector stack and then creating a reverse of the input string.
string palindrome(string str1)
{
	int size = str1.length();
	Stack stack;

	for (int i = 0; i < size; i++)
	{
		stack.push (str1[i]);
	}

	string str2 = str1;
	int size2 = size;
	for (int i = 0; i < size2; i++)
	{
		stack.pop(str2[i]);
		size--;
	}

	if (str1 != str2)
	{
		str1 = str1 + str2;
	}
	return str1;
}

void queue(int turns, int outPercent, int inPercent)
{
	double averageLength=5;
	cout << "The starting queue is 5 integers long." << endl;
	vector<int> queue;
	for (int i = 0; i < 5; i++)
	{
		queue.push_back(rand());
	}

	for (int i = 1; i < turns+1; i++)
	{
		int length;
		int add = random(inPercent);
		if(add != -1)
		{
			queue.push_back(add);
		}

		if (!queue.empty())
		{
			int remove = random(outPercent);
			if(remove != -1)
			{
				vector<int>::iterator iter = queue.begin();
				queue.erase(iter);
			}
		}
		length = queue.size();
		double average;
		average = (averageLength * (i - 1) + length) / i;
		averageLength = average;
		cout << "The average length for round " << i << " is: " << average << endl;
	}
	queue.clear();
}

//returns a random integer or returns -1 not to add
int random(int percentage)
{
	if (rand() % 100 < percentage)
		return rand();
	else
		return -1;
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