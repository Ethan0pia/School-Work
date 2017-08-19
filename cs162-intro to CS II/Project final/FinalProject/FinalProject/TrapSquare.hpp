/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the trap space.
*************************************************************************/

#ifndef TRAPSQUARE_HPP
#define TRAPSQUARE_HPP
#include "Space.hpp"

class TrapSquare : public Space
{
private:
	bool loop = false;

public:
	int action();
	char type();
	int trap(int);
};

#endif