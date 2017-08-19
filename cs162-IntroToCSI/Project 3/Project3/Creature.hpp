/**********************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the header file for the Creature class.
***********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
protected:
	int attDieSides;
	int numOfAttDie;
	int defDieSides;
	int numOfDefDie;
	int strength;
	int armor;

public:
	//constructor
	Creature() {};
	//attack roll
	virtual int rollAttack();
	//defence roll, takes int damage and decreases strength after rolling a defence roll.
	virtual void rollDefence(int);
	//checks to see if monster is dead.
	virtual bool death();
};

#endif