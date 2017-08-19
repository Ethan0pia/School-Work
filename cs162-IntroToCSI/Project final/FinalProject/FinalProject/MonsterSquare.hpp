/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the monster space.
*************************************************************************/

#ifndef MONSTERSQUARE_HPP
#define MONSTERSQUARE_HPP
#include<string>
#include "Space.hpp"

class MonsterSquare : public Space
{
private:
	bool loops = false;
	std::string monster;
	int strength;
	int defense;
	int die = 1;
	int sides;

public:
	//sets up the coresponding mob
	MonsterSquare(int);
	//does the action for the space.
	int action();
	//returns the char that coresponds with the square
	char type();
	//fights a monster if there, otherwise returns -1
	int fight();
	void defend(int);
	int getStr();

};

#endif