/**********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the implementation file for the LoadedDie class.
***********************************************************************/
#include <stdlib.h>     // srand, rand
#include "LoadedDie.hpp"
#include<iostream>
#include<iostream>
using std::cout;

//constructor that takes number of sides of a die and saves it.
LoadedDie::LoadedDie(int _sides)
{
	sides = _sides;
}

//returns a roll of a die by taking a random integer and mod that number to get a value of the die.
//The loaded version adds 1 to the value rolled before returning the value.
int LoadedDie::getRoll()
{
	int roll;
	roll = rand() % sides;
	cout << "The magical die made the roll displayed below better. (Loaded)" << std::endl;
	if (roll == 0)
	{
		roll = sides;
	}
	roll++;//loaded die gets +1
	return roll;
}