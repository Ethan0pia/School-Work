/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the vampire boss space.
*************************************************************************/

#include"VampireSquare.hpp"

//does the action for the space.
int VampireSquare::action()
{
	std::cout << "You find yourself in a room with a coffin." << std::endl;
	std::cout << "Being the stupid adventurer that you are, you decide to open it." << std::endl;
	std::cout << "After pushing the coffin lid open, you find yourself staring at an undead vampire." << std::endl;
	std::cout << "You take a quick step back and prepare to fight." << std::endl;
	return 3;
}

//returns the char that coresponds with the square
char VampireSquare::type()
{
	return 'v';
}

//fights a monster if there, otherwise returns -1
int VampireSquare::fight()
{
	//tells main that there is a mob to fight.
	if(strength<0)
	{
		return -1;
	}
	else
	{
		int roll=0;
		for (int i = 0; i < die; i++)
		{
			roll += rand() % sides;
		}
		return roll;
	}
}

void VampireSquare::defend(int hit)
{
	int roll = 0;
	for (int i = 0; i < die; i++)
	{
		roll += rand() % sides;
	}
	if (hit > roll)
	{
		hit = hit - defense;
	}
	if (hit < 0 || hit < roll)
	{
		hit = 0;
	}
	if (hit > 0)
	{
		strength -= hit;
	}
	std::cout << "The vampire was hit for " << hit << " damage." << std::endl;
}

int VampireSquare::getStr()
{
	return strength;
}