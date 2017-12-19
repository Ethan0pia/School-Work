/**********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the header file for the die class.
***********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP


class Die
{

protected:
	int sides;

public:
	//required default constructor to avoid errors from LoadedDie constructor.
	Die();
	//constructor for Die that takes the number of sides of a die and saves it
	Die(int);

	//returns a roll of a die by taking a random integer and mod that number to get a value of the die.
	virtual int getRoll();
};
#endif