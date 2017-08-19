/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child of space for the empty square class.
*************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP
#include<iostream>
class Space
{
private:
	Space *up = NULL;
	Space *down = NULL;
	Space *left = NULL;
	Space *right = NULL;

protected:
	bool key;

public:
	Space();
	//sets the surrounding squares.
	void setPointers(Space*, Space*, Space*, Space*);
	//does the action for the specific square.
	virtual int action() = 0;
	//sets key to true;
	void setKey();
	//returns key
	bool getKey();
	//returns the char that coresponds with the square
	virtual char type() = 0;
	//returns the new location of the player, unless it hits a wall.
	Space* getDirection(char, Space*);
	//fights a monster if there, otherwise returns -1
	virtual int fight();
	//activates trap damage, takes in dexterity, returns -1 if no trap.
	virtual int trap(int);
	//rolls a defence and applies dmg
	virtual void defend(int) {};
	virtual int getStr();
};



#endif