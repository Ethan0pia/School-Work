/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the header file for the BlueMen class.
***********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen : public Creature
{
private:
	int damage;

public:
	//constructor
	BlueMen();
	//blueMen death override to decrease their defence die when one entity within the mob dies.
	bool death();
};


#endif