/***********************************************************************
** Program name:Queue
** Authors: Ethan Dunham
** Due Date: 2/26/17
** Description: This is the header file for the Queue class.
**		It will add items to a queue, delete them, and display them.
*************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Creature.hpp"
class Queue
{
private:
	struct p1Queue
	{
		Creature *creature;
		p1Queue *next;
		p1Queue *previous;
		p1Queue()
		{
			Creature *creature = NULL;
		}
	};
	struct p2Queue
	{
		Creature *creature;
		p2Queue *next;
		p2Queue *previous;
		p2Queue()
		{
			Creature *creature = NULL;
		}
	};
	struct deadQueue
	{
		Creature *creature;
		deadQueue *next;
		deadQueue *previous;
		deadQueue()
		{
			Creature *creature = NULL;
		}
	};

	p1Queue *p1Front;
	p1Queue *p1Back;
	p2Queue *p2Front;
	p2Queue *p2Back;
	deadQueue *deadBack;
	deadQueue *deadFront;
	int p1Score = 0;
	int p2Score = 0;
	int size;
	char disp;

public:
	Queue(int, char);
	void addBack(int, std::string, int);
	void clear();
	void fight();
	void display();
};



#endif
