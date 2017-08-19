/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for the Barbarian class.
**************************************************************************/

#include"Barbarian.hpp"

//constructor
Barbarian::Barbarian(std::string name)
{
	attDieSides = 6;
	numOfAttDie = 2;
	defDieSides = 6;
	numOfDefDie = 2;
	totalStr = strength = 12;
	armor = 0;
	this->name = name;
	this->type = "Barbarian";
}