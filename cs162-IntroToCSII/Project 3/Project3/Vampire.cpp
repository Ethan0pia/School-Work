/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the Vampire class.
***********************************************************************/

#include "Vampire.hpp"
#include <stdlib.h> //srand, rand

//constructor
Vampire::Vampire()
{
	attDieSides = 12;
	numOfAttDie = 1;
	defDieSides = 6;
	numOfDefDie = 1;
	strength = 18;
	armor = 1;
}

//overrides defence roll to call charm. If charm is true, it skips the attack calculations.
void Vampire::rollDefence(int dmg)
{
	int roll;
	int hit;
	if (!charm())
	{
		roll = rand() % defDieSides + 1;
		hit = dmg - roll - armor;
		if (hit > 0)
		{
			strength = strength - hit;
		}
	}
}

//charm has a 50% chance of being true. Stops attack from happening if true.
bool Vampire::charm()
{
	bool charm = false;
	if (rand() % 2 == 1)
	{
		charm = true;
	}
	return charm;
}