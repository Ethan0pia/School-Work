/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the HarryPotter class.
**************************************************************************/

#include "HarryPotter.hpp"
//constructor
HarryPotter::HarryPotter()
{
	attDieSides = 6;
	numOfAttDie = 2;
	defDieSides = 6;
	numOfDefDie = 2;
	strength = 10;
	armor = 0;
	deaths = 0;
}
//death override to bring HP back to life if he hasnt died before.
bool HarryPotter::death()
{
	bool death;
	if (strength <= 0)
	{
		if (deaths == 0)
		{
			deaths++;
			strength = 20;
			death = false;
		}
		else
		{
			death = true;
		}
	}
	else
	{
		death = false;
	}
	return death;
}