/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the wall.
*************************************************************************/

#ifndef WALLSQUARE_HPP
#define WALLSQUARE_HPP
#include "Space.hpp"

class WallSquare : public Space
{
	//returns the char that coresponds with the square
	char type();
	//actions
	int action();
};

#endif
