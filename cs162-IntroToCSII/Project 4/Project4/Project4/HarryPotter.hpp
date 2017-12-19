/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the header file for the HarryPotter class.
***********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class HarryPotter : public Creature
{
private:
	void Hogwarts();
	int deaths;

public:
	HarryPotter(std::string);
	bool death();
};


#endif