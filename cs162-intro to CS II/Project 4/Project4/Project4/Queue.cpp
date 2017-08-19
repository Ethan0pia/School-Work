/***********************************************************************
** Program name:Queue
** Authors: Ethan Dunham
** Due Date: 2/26/17
** Description: This is the header file for the Queue class.
**		It will add items to a queue, delete them, and display them.
*************************************************************************/

#include"Queue.hpp"
#include"Vampire.hpp"
#include"Medusa.hpp"
#include"HarryPotter.hpp"
#include"BlueMen.hpp"
#include"Barbarian.hpp"
#include<iostream>

using std::cout;
using std::endl;


//constructor
Queue::Queue(int size, char disp)
{
	this->disp = disp;
	this->size = size;
	p1Front = new p1Queue();
	p1Front->next = p1Front;
	p1Front->previous = p1Front;
	p1Back = p1Front;
	for (int i = 0; i < size-1; i++)
	{
		p1Back->next = new p1Queue();
		p1Back->next->previous = p1Back;
		p1Back = p1Back->next;
		p1Back->next = p1Front;
		p1Front->previous = p1Back;
	}
	p1Back = p1Front;

	p2Front = new p2Queue();
	p2Front->next = p2Front;
	p2Front->previous = p2Front;
	p2Back = p2Front;
	for (int i = 0; i < size - 1; i++)
	{
		p2Back->next = new p2Queue();
		p2Back->next->previous = p2Back;
		p2Back = p2Back->next;
		p2Back->next = p2Front;
		p2Front->previous = p2Back;
	}
	p2Back = p2Front;

	deadBack = deadFront = NULL;
}

//adds value to the end of the queue
void Queue::addBack(int value, std::string name, int player)
{
	if (player == 1)
	{
		if (value == 1)//vamp
		{
			p1Back->creature = new Vampire(name);
		}
		else if (value == 2)//barb
		{
			p1Back->creature = new Barbarian(name);
		}
		else if (value == 3)//bluemen
		{
			p1Back->creature = new BlueMen(name);
		}
		else if (value == 4)//madusa
		{
			p1Back->creature = new Medusa(name);
		}
		else//HP
		{
			p1Back->creature = new HarryPotter(name);
		}

		p1Back = p1Back->next;
	}
	else
	{
		if (value == 1)//vamp
		{
			p2Back->creature = new Vampire(name);
		}
		else if (value == 2)//barb
		{
			p2Back->creature = new Barbarian(name);
		}
		else if (value == 3)//bluemen
		{
			p2Back->creature = new BlueMen(name);
		}
		else if (value == 4)//madusa
		{
			p2Back->creature = new Medusa(name);
		}
		else//HP
		{
			p2Back->creature = new HarryPotter(name);
		}

		p2Back = p2Back->next;
	}
}

//clears the list
void Queue::clear()
{
	while (p1Front->next != p1Front)
	{
			p1Queue *temp = p1Front->next;
			p1Front->next = p1Front->next->next;
			temp->next->previous = p1Front;
			delete temp;
	}
	
	while (p2Front->next != p2Front)
	{
		p2Queue *temp = p2Front->next;
		p2Front->next = p2Front->next->next;
		temp->next->previous = p2Front;
		delete temp;
	}

	while (deadFront->next != NULL)
	{
		deadQueue *temp = deadFront;
		deadFront = deadFront->next;
		delete temp;
	}
	delete deadFront;
}

//fights the 2 groups.
void Queue::fight()
{
	int turns = 0;
	int currentPlayer = 1;
	int attRoll;
	do {
		turns++;
		do
		{
			attRoll = 0;
			if (currentPlayer == 1)
			{
				attRoll = p1Front->creature->rollAttack();
				p2Front->creature->rollDefence(attRoll);
				currentPlayer = 2;
			}
			else
			{
				attRoll = p2Front->creature->rollAttack();
				p1Front->creature->rollDefence(attRoll);
				currentPlayer = 1;
			}
		} while (!p1Front->creature->death() && !p2Front->creature->death());
		if (p1Front->creature->death())
		{
			if (disp == 'y')
			{
				cout << "Player 1 used a " << p1Front->creature->typeOfMob() << " named " << p1Front->creature->getName() << "." << endl;
				cout << "Player 2 used a " << p2Front->creature->typeOfMob() << " named " << p2Front->creature->getName() << "." << endl;
				cout << "Player 2 won the round. Player 1 has died and been sent to the graveyard." << endl;
			}
			//remove creature node from line up
			if (deadFront == NULL)
			{
				deadFront = new deadQueue();
				deadBack = deadFront;
				deadBack->creature = p1Front->creature;
				deadFront->previous = NULL;
				deadFront->next = NULL;
			}
			else
			{
				deadBack->next = new deadQueue();
				deadBack->next->previous = deadBack;
				deadBack->next->creature = p1Front->creature;
				deadBack = deadBack->next;
				deadBack->next = NULL;
			}
			if (p1Front->next != p1Back)
			{
				p1Queue *temp = p1Front;
				p1Front->previous->next = p1Front->next;
				p1Front->next->previous = p1Front->previous;
				p1Front = p1Front->next;
				delete temp;
			}
			//move p2 to back
			p2Front->creature->winner();
			p2Back = p2Front;
			p2Front = p2Front->next;
			p2Score++;
		}
		else
		{
			if (disp == 'y')
			{
				cout << "Player 1 used a " << p1Front->creature->typeOfMob() << " named " << p1Front->creature->getName() << "." << endl;
				cout << "Player 2 used a " << p2Front->creature->typeOfMob() << " named " << p2Front->creature->getName() << "." << endl;
				cout << "Player 1 won the round. Player 2 has died and been sent to the graveyard." << endl;
			}
			//remove creature node from line up
			if (deadFront == NULL)
			{
				deadFront = new deadQueue();
				deadBack = deadFront;
				deadBack->creature = p2Front->creature;
				deadFront->previous;
				deadFront->next = NULL;
			}
			else
			{
				deadBack->next = new deadQueue();
				deadBack->next->previous = deadBack;
				deadBack->next->creature = p2Front->creature;
				deadBack = deadBack->next;
				deadBack->next = NULL;
			}
			if (p2Front != p2Back)
			{
				p2Queue *temp = p2Front;
				p2Front->previous->next = p2Front->next;
				p2Front->next->previous = p2Front->previous;
				p2Front = p2Front->next;
				delete temp;
			}
			//move p1 to back
			p1Front->creature->winner();
			p1Back = p1Front;
			p1Front = p1Front->next;
			p1Score++;
		}
		cout << endl;
		if (disp == 'y')
		{
			cout << "Round " << turns << ": The current score is:" << endl;
			cout << "Player 1: " << p1Score << endl;
			cout << "Player 2: " << p2Score << endl;
			cout << endl;
		}
	} while(p1Score < size && p2Score < size);
	cout << "The final score is:" << endl;
	cout << "Player 1: " << p1Score << endl;
	cout << "Player 2: " << p2Score << endl;
	if (p1Score > p2Score)
	{
		cout << "Player 1 won the tournament." << endl;
	}
	else
	{
		cout << "Player 2 won the tournament." << endl;
	}

	char display;
	do {
		cout << "Would you like to see the loser pool? y or n" << endl;
		std::cin >> display;
	} while (std::cin.fail() ||(display != 'y' && display != 'n'));
	if (display == 'y')
	{
		Queue::display();
	}
}

void Queue::display()
{
	deadQueue *temp = deadBack;
	while (temp != NULL)
	{
		cout << "A " << temp->creature->typeOfMob() << " named " << temp->creature->getName() << "." << endl;
		temp = temp->previous;
	}
	delete temp;
}