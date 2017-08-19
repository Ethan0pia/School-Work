/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the door space.
*************************************************************************/

#ifndef DOORSQUARE_HPP
#define DOORSQUARE_HPP
#include "Space.hpp"

class DoorSquare : public Space
{
	//does the action for the space.
	int action();
	//returns the char that coresponds with the square
	char type();
};

#endif
