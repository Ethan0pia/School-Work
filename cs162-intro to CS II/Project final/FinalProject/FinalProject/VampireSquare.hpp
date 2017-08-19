/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the vampire boss space.
*************************************************************************/

#ifndef VAMPIRESQUARE_HPP
#define VAMPIRESQUARE_HPP
#include "Space.hpp"

class VampireSquare : public Space
{
private:
	bool loops = false;
	int strength = 20;
	int defense = 2;
	int die = 2;
	int sides = 4;

public:
	//does the action for the space.
	int action();
	//returns the char that coresponds with the square
	char type();
	//fights a monster if there, otherwise returns -1
	int fight();
	void defend(int);
	int getStr();
};

#endif