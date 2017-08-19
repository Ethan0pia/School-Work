/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the parent class for all the squares of the game.
*************************************************************************/


#include "Space.hpp"
#include<iostream>
#include<string>

Space::Space()
{
	key = false;
}

void Space::setKey()
{
	key = true;
}

void Space::setPointers(Space* up, Space* dn, Space* lf, Space* rt)
{
	this->up = up;
	down = dn;
	left = lf;
	right = rt;

}

Space* Space::getDirection(char direction, Space* current)
{
	if (direction == 'u')
	{
		if (up->type() == 'w')
		{
			std::cout << "You see a wall. Try another direction." << std::endl;
			return current;
		}
		return up;
	}
	if (direction == 'd')
	{
		if (down->type() == 'w')
		{
			std::cout << "You see a wall. Try another direction." << std::endl;
			return current;
		}
		if (down->type() == 'd' && !down->getKey())
		{
			std::cout << "You see a locked door, but you do not have a key. Try another direction." << std::endl;
			return current;
		}
		return down;
	}
	if (direction == 'l')
	{
		if (left->type() == 'w')
		{
			std::cout << "You see a wall. Try another direction." << std::endl;
			return current;
		}
		return left;
	}
	if (direction == 'r')
	{
		if (right->type() == 'w')
		{
			std::cout << "You see a wall. Try another direction." << std::endl;
			return current;
		}
		return right;
	}
	return current;
}

//returns key setting
bool Space::getKey()
{
	return key;
}

//fights if there is a monster present, otherwise returns -1.
int Space::fight()
{
	return -1;
}

//returns damage from a trap, otherwise returns -1.
int Space::trap(int dexterity)
{
	return 0;
}

int Space::getStr()
{
	return 0;
}