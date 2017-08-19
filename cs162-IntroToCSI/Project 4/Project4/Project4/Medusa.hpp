/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the header file for the Medusa class.
***********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa : public Creature
{

public:
	//constructor
	Medusa(std::string);
	//attack roll override, returns 400 if a perfect roll is made.
	int rollAttack();
};


#endif