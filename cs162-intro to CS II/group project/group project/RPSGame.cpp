/***********************************************************************
** Program name:Group Project RPS Game
** Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
** Due Date: 2/26/17
** Description: This is the implementation for the RPSGame class.
**		It contains a menu that will get the RPS info and
**		then play the game by calling the correct functions.
*************************************************************************/


#include <iostream>
#include <cstdlib>
#include "Paper.hpp"
#include "Rock.hpp"
#include "Scissors.hpp"
#include "Tool.hpp"
#include "RPSGame.hpp"
#include<string>

using std::cin;
using std::cout;
using std::endl;


bool cinFail();

//constructor
RPSGame::RPSGame()
{
	computer_wins = ties = human_wins = 0;
}



//starts the game process.
void RPSGame::playGame()
{
	int status;
	do {
		status = menu(); // calls menu to get play info.

		if (status == 5)
		{
			computer_wins = ties = human_wins = 0;
		}

		if (status < 4)
		{
			int winner;
			std::cout << std::string(5, '\n');//creates a nice menu look without clutter.

			winner = human->fight(computer);//calls the fight function
			cout << winner << endl;
			cout << "The human used ";
			if (humanType == 'r') cout << "rock";
			if (humanType == 'p') cout << "paper";
			if (humanType == 's') cout << "scissors";
			cout << "." << endl;
			cout << "The computer used ";
			if (computerType == 'r') cout << "rock";
			if (computerType == 'p') cout << "paper";
			if (computerType == 's') cout << "scissors";
			cout << "." << endl;

			if (winner == 1)
			{
				human_wins++;
				cout << "The human won." << endl;
			}
			else if (winner == 2)
			{
				computer_wins++;
				cout << "The computer won." << endl;
			}
			else
			{
				cout << "This round was a draw." << endl;
				ties++;
			}
			delete human;//free memory
			delete computer;//free memory
		}

		cout << "The current score is:" << endl;
		cout << "Human: " << human_wins << endl;
		cout << "Computer: " << computer_wins << endl;
		cout << "Ties: " << ties << endl;

	} while (status != 6);
}

//menu function sets all the relevant data for running the program 
//as well as calculated random values for those numbers not picked.
int RPSGame::menu()
{
	int status = 0;
	do
	{
		int option;

		cout << std::string(2, '\n');

		do {//all do loops are validation of cin.fail()
			cout << "Option 1: Choose rock." << endl;
			cout << "Option 2: Choose paper." << endl;
			cout << "Option 3: Choose Scissors." << endl;
			cout << "Option 4: Display current score." << endl;
			cout << "Option 5: Start a new game." << endl;
			cout << "Option 6: End program.*" << endl;
			cin >> option;
			cout << std::string(2, '\n');
		} while (cinFail() || option > 6 || option < 1);

		switch (option)
		{
		case 1://rock
			cout << std::string(2, '\n');
			human = new Rock();
			humanType = 'r';
			status = 1;
			break;

		case 2://paper
			cout << std::string(2, '\n');
			human = new Paper();
			humanType = 'p';
			status = 2;
			break;

		case 3://scissors
			cout << std::string(2, '\n');
			human = new Scissors();
			humanType = 's';
			status = 3;
			break;

		case 4://scores
			cout << std::string(2, '\n');
			cout << "The current scores are:" << endl;
			cout << "Human: " << human_wins << endl;
			cout << "Computer: " << computer_wins << endl;
			cout << "Ties: " << ties << endl;
			cout << std::string(2, '\n');
			status = 4;
			break;

		case 5://start over
			status = 5;
			break;

		case 6://end
			status = 6;
		}
	} while (status == 4);
	if (status < 5)
	{
		int randomGen = rand() % 3;
		if (randomGen == 0)
		{
			computer = new Rock();
			computerType = 'r';
		}

		if (randomGen == 1)
		{
			computer = new Paper();
			computerType = 'p';
		}

		if (randomGen == 2)
		{
			computer = new Scissors();
			computerType = 's';
		}
	}
	return status;
}

//Stops endless loops from user entering incorrect information that breaks the program.
bool cinFail()
{
	bool state;//validates cin statements
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(300, '\n');
		state = true;
	}
	else
	{
		state = false;
	}
	return state;
}
