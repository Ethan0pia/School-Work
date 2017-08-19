/***********************************************************************
** Program name:Queue
** Authors: Ethan Dunham
** Due Date: 2/26/17
** Description: This is the header file for the Queue class.
**		It will add items to a queue, delete them, and display them.
*************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP


class Queue
{
private:
	struct myQueue
	{
		int value;
		myQueue *next;
		myQueue *previous;
		myQueue(int value1)
		{
			value = value1;
		}
	};

	myQueue *front;
	myQueue *back;

public:
	Queue();
	void addBack(int);
	int getFront();
	void removeFront();
	void print();
	void clear();



};



#endif
