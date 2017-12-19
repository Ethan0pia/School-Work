/***********************************************************************
** Program name:Queue
** Authors: Ethan Dunham
** Due Date: 2/26/17
** Description: This is the header file for the Queue class.
**		It will add items to a queue, delete them, and display them.
*************************************************************************/

#include"Queue.hpp"
#include<iostream>

using std::cout;
using std::endl;


//constructor
Queue::Queue()
{
	front = new myQueue(-1);
	front->next = front;
	front->previous = front;
	back = front;
}

//adds value to the end of the queue
void Queue::addBack(int value1)
{
	if (back->next->value != -1)
	{
		back->next = new myQueue(value1);
		back->next->previous = back;
		back->next->next = front;
		back = back->next;
		front->previous = back;
		if (back->previous == front)
		{
			front->next = back;
		}
	}
	else
	{
		back->next->value = value1;
		back->next->previous = back;
		back = back->next;
		back->next = front;
	}
}

//returns the value of the front of the queue
int Queue::getFront()
{
	if (front->value != -1)
	{
		return front->value;
	}
	else
	{
		cout << "The queue is empty." << endl;
			return -1;
	}
}

//removes the front of the queue
void Queue::removeFront()
{
	if (front->value != -1)
	{
		front->value = -1;
		front = front->next;
	}
	else
	{
		cout << "The queue is empty." << endl;
	}
}

//prints the current queue
void Queue::print()
{
	myQueue *temp = front;
	if (front->value == -1)
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		if (temp == back)
		{
			cout << temp->value << ' ';
		}
		else
		{
			do
			{
				cout << temp->value << ' ';
				temp = temp->next;
				if (temp == back)
				{
					cout << temp->value << ' ';
				}
			} while (temp != back);
		}
	}
}

//clears the list
void Queue::clear()
{
	while (front->next != back)
	{
		myQueue *temp = front->next;
		front->next = front->next->next;
		temp->next->previous = front;
		delete temp;
	}
	if (front == back)
	{
		delete front;
	}
	else
	{
		delete front;
		delete back;
	}
}