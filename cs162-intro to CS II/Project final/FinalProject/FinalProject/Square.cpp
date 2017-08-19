/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the class for the chest square.
*************************************************************************/


#include "Square.hpp"
#include<iostream>
#include<string>

int Square::action()
{
	std::cout << "You find yourself in an empty hallway." << std::endl;
	return 1;
}

char Square::type()
{
	return 'e';
}
