/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the key space.
*************************************************************************/

#ifndef KEYSQUARE_HPP
#define KEYSQUARE_HPP
#include "Space.hpp"

class KeySquare : public Space
{
	int action();
	char type();
};

#endif