/***********************************************************************
** Program name:Queue
** Authors: Ethan Dunham
** Due Date: 2/26/17
** Description: This is the menu/main for the queue program.
**		It contains a menu that will get integers and add
**		them to a queue and delete them.
*************************************************************************/


#include <iostream>
#include<string>
#include "Queue.hpp"

using std::cin;
using std::cout;
using std::endl;

bool cinFail();

//main/menu
int main()
{
	Queue theQueue;
	int value;
	char option;
	do
	{
		cout << std::string(2, '\n');

		do {//all do loops are validation of cin.fail()
			cout << "a.Enter a value to be added to the queue" << endl;
			cout << "b.Display first node(front) value" << endl;
			cout << "c.Remove first node(front) value" << endl;
			cout << "d.Display the queue contents" << endl;
			cout << "x.Exit" << endl;
			cin >> option;

			cout << std::string(2, '\n');
		} while (cinFail() || (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'x'));

		switch (option)
		{
		case 'a'://enter value to add
			do {
				cout << "Enter a positive integer value to add to the back of the queue." << endl;
				cin >> value;
			} while (cinFail() || value < 0);
			theQueue.addBack(value);
			break;

		case 'b'://display first
			value = theQueue.getFront();
			if (value != -1)
			{
				cout << "The front of the queue has a value of: " << value << endl;
			}
			break;

		case 'c'://remove first
			theQueue.removeFront();
			break;

		case 'd'://display contents
			theQueue.print();
			break;

		case 'x'://exit
			theQueue.clear();
			break;
		}
	} while (option != 'x');

	return 1;
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
