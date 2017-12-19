/**********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the header file for the LoadedDie class.
***********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die
{

public:
	//constructor that takes number of sides of a die and saves it.
	LoadedDie(int);

	//returns a roll of a die by taking a random integer and mod that number to get a value of the die.
	//The loaded version adds 1 to the value rolled before returning the value.
	int getRoll();
};
#endif
