/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the class for the chest square.
*************************************************************************/

#include"ChestSquare.hpp"
#include<iostream>

int ChestSquare::action()
{
	std::cout << "You find a ragged looking chest..." << std::endl;
	std::cout << "Upon closer inspection, you find a weapon that is slightly better than your current weapon." << std::endl;
	std::cout << "Congratulations, your damage has increased by +5." << std::endl;
	return 4;
}
char ChestSquare::type()
{
	return 'c';
}