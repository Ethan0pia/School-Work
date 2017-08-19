/*********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the main for the dice war program.
*********************************************************************/

#include <cstdlib>
#include <time.h>
#include<iostream>
#include "Game.hpp"

//runs the game after creating a game object
int main() {
	srand(time(NULL));
	Game game1;
	game1.menu();
	int hat;
	std::cin>>hat;
	return 0;
}