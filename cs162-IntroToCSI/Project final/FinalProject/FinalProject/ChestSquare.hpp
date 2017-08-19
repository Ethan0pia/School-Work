/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the door space.
*************************************************************************/

#ifndef CHESTSQUARE_HPP
#define CHESTSQUARE_HPP
#include "Space.hpp"

class ChestSquare : public Space
{
	int action();
	char type();
};

#endif