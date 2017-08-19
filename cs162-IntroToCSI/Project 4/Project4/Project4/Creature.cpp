/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the Creature class.
***********************************************************************/

#include"Creature.hpp"
#include <stdlib.h> //srand, rand
#include<iostream>

//attack roll, returns a random number based on number of die and sides.
int Creature::rollAttack()
{
	int roll = 0;
	for (int i = 0; i < numOfAttDie; i++)
	{
		roll += (rand() % attDieSides + 1);
	}
	return roll;
}

//defence roll, takes int damage and decreases strength after rolling a defence roll.
void Creature::rollDefence(int dmg)
{
	int hit;
	int roll = 0;
	for (int i = 0; i < numOfDefDie; i++)
	{
		roll += (rand() % defDieSides + 1);
	}
	hit = dmg - roll - armor;
	if (hit > 0)
	{
		strength = strength - hit;
	}
}

//checks to see if monster is dead.
bool Creature::death()
{
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

std::string Creature::typeOfMob()
{
	return type;
}

std::string Creature::getName()
{
	return name;
}

void Creature::winner()
{
	int dmg;
	dmg = totalStr - strength;
	strength = strength + (dmg / 2);
}