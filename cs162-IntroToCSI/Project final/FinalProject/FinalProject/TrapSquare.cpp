/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the class for the trap square.
*************************************************************************/

#include"TrapSquare.hpp"
#include<iostream>

int TrapSquare::action()
{
	std::cout << "You see what looks like an empty room." << std::endl;
	std::cout << "As you step into the middle of the hallway, you hear a soft click." << std::endl;
	return 6;
}
char TrapSquare::type()
{
	return 't';
}

//returns damage from a trap, otherwise returns -1.
int TrapSquare::trap(int dexterity)
{
	if (!loop)
	{
		std::cout << "All of a sudden, you see a crossbow bolt come flying at you." << std::endl;
		std::cout << "You attempt to use your dexterity to dodge the bolt." << std::endl;
		int hit;
		hit = (rand() % 10) / dexterity;
		loop = true;
		return hit;
	}
	else
	{
		std::cout << "You cower in fear that another bolt will fly at you, but none do." << std::endl;
		return 0;
	}
}