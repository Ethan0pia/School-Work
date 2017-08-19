/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the door space.
*************************************************************************/

#include "DoorSquare.hpp"
#include<iostream>
#include<string>

//does the action for the space.
int DoorSquare::action()
{
	if (key)
	{
		//opens the door
		std::cout << "You find a heavy door. It is locked tightly, but the key you found fits perfectly." << std::endl;
		std::cout << "You unlock the door and push it inward. It makes a loud creaking sound." << std::endl;
		std::cout << "It is clear that this door has not been opened in years." << std::endl;
		return 2;
	}
	else
	{
		std::cout << "The door is shut tight and locked. You do not have a key." << std::endl;
		return -1;
	}
}

//returns the char that coresponds with the square
char DoorSquare::type()
{
	return 'd';
}