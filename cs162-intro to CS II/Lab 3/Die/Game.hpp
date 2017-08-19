/*********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the header file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
	int p1Sides = 0;
	int p2Sides = 0;
	char p1Loaded = '0';
	char p2Loaded = '0';
	int p1Roll, p2Roll;
	int p1Score = 0;
	int p2Score = 0;
	int turns = 0;

	//plays the game. It keeps track of the current score, the rolls, etc. It uses variables to 
	//determine which function to call for each die and eventually outputs the winner.
	void playGame();

	//Stops endless loops from user entering incorrect information that breaks the program.
	bool cinFail();

public:
	//menu function sets all the relevant data for running the program 
	//as well as calculated random values for those numbers not picked.
	void menu();
};
#endif