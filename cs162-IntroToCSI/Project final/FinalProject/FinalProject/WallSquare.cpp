/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the wall.
*************************************************************************/

#include "WallSquare.hpp"

//returns the char that coresponds with the square
char WallSquare::type()
{
	return 'w';
}

int WallSquare::action()
{
	return 0;
}