/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the child class for the key space.
*************************************************************************/

#include"KeySquare.hpp"
#include<iostream>

int KeySquare::action()
{
	std::cout << "You see a key glinting on the floor." << std::endl;
	std::cout << "You bend down and pick it up." << std::endl;
	std::cout << "Then, you jump back quickly, cowering in a nearby corner..." << std::endl;
	std::cout << "Nothing happens." << std::endl;
	key = true;
	return 5;
}

char KeySquare::type()
{
	return 'k';
}