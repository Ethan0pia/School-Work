/**********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the header file for the die class.
***********************************************************************/
#include <stdlib.h>     // srand, rand
#include"Die.hpp"
#include<iostream>

//required default constructor to avoid errors from LoadedDie constructor.
Die::Die()
{}

//constructor for Die that takes the number of sides of a die and saves it
Die::Die(int _sides)
{
	sides = _sides;
}

//returns a roll of a die by taking a random integer and mod that number to get a value of the die.
int Die::getRoll()
{
	int roll;
	roll = rand() % sides;

	if (roll == 0)//can't roll a 0, so 0 equals the max value
	{
		roll = sides;
	}

	return roll;
}