/*********************************************************************
** Program name:Group Project RPS Game
** Authors: Ethan Dunham
** Date: 2/10/17
** Description: This is the header for the RPSGame class.
**		It contains a menu that will get the RPS info and
**		then play the game by calling the correct functions.
*********************************************************************/

#ifndef RPSGame_HPP
#define RPSGame_HPP
#include "Tool.hpp"

class RPSGame
{
private:
	int human_wins;
	int computer_wins;
	int ties;
	Tool *human;
	Tool *computer;
	char humanType;
	char computerType;

	int menu();

public:
	RPSGame();
	void playGame();
};

#endif
