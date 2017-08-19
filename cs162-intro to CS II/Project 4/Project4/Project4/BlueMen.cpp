/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the BlueMen class.
**************************************************************************/

#include"BlueMen.hpp"

//constructor
BlueMen::BlueMen(std::string name)
{
	attDieSides = 10;
	numOfAttDie = 2;
	defDieSides = 6;
	numOfDefDie = 3;
	totalStr = strength = 12;
	armor = 3;
	this->name = name;
	this->type = "Blue Men";
}

//blueMen death override to decrease their defence die when one entity within the mob dies.
bool BlueMen::death()
{
	if (strength < 5)
	{
		numOfDefDie = 1;
	}
	else if (strength < 9)
	{
		numOfDefDie = 2;
	}
	else
	{
		numOfDefDie = 3;
	}

	bool death;
	if (strength <= 0)
	{
		death = true;
	}
	else
	{
		death = false;
	}
	return death;
}