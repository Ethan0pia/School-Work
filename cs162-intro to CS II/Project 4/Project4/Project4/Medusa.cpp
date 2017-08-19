/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the Medusa class.
**************************************************************************/

#include "Medusa.hpp"
#include <stdlib.h> //srand, rand

//constructor
Medusa::Medusa(std::string name)
{
	attDieSides = 6;
	numOfAttDie = 2;
	defDieSides = 6;
	numOfDefDie = 1;
	totalStr = strength = 8;
	armor = 3;
	this->name = name;
	this->type = "Medusa";
}

//attack roll override, returns 400 if a perfect roll is made.
int Medusa::rollAttack()
{
	int roll = 0;
	for (int i = 0; i < numOfAttDie; i++)
	{
		roll += (rand() % attDieSides + 1);
	}
	if (roll == 12)
	{
		roll = 400;//instant win special
	}
	return roll;
}

