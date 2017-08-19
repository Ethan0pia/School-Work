/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the vampire boss space.
*************************************************************************/

#include"MonsterSquare.hpp"

MonsterSquare::MonsterSquare(int mob)
{
	bool player = false;
	key = false;
	if (mob == 1)
	{
		monster = "goblin named Stupid";
		sides = 2;
		strength = 5;
		defense = 0;
	}
	else if (mob == 2)
	{
		monster = "lion named Coward";
		sides = 3;
		strength = 10;
		defense = 1;
	}
	else
	{
		monster = "barbarian named Jim";
		sides = 4;
		strength = 12;
		defense = 1;
	}
}


//does the action for the space.
int MonsterSquare::action()
{
	if (strength > 0)
	{
		std::cout << "You find yourself in a hallway." << std::endl;
		std::cout << "Ahead of you, you see a menacing monster." << std::endl;
		std::cout << "It charges at you and you see that it is a " << monster << "." << std::endl;
		std::cout << "You prepare to fight." << std::endl;
	}
	else
	{
		std::cout << "You find yourself in a hallway." << std::endl;
		std::cout << "Ahead of you, you see a dead monster." << std::endl;
	}
	return 3;
}

//returns the char that coresponds with the square
char MonsterSquare::type()
{
	return 'v';
}

//fights a monster if there, otherwise returns -1
int MonsterSquare::fight()
{
	int roll;
	//tells main that there is a mob to fight.
	if (strength<0)
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

void MonsterSquare::defend(int hit)
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
	std::cout << "The monster was hit for " << hit << " damage." << std::endl;

}

int MonsterSquare::getStr()
{
	return strength;
}