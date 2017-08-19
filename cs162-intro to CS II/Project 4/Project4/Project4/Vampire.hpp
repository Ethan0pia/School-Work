/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the header file for the Vampire class.
***********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire : public Creature
{
private:
	//50% chance of returning true to stop an attack.
	bool charm();

public:
	//constructor
	Vampire(std::string);
	//overrides defence roll to call charm. If charm is true, it skips the attack calculations.
	void rollDefence(int);
};


#endif