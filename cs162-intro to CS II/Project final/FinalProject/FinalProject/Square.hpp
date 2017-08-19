/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child of space for the empty square class.
*************************************************************************/

#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Space.hpp"

class Square : public Space
{
public:
	//does the action for the specific square.
	int action();
	//returns the char that coresponds with the square
	char type();
};



#endif