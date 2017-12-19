/*********************************************************************
** Program name:Dice War
** Author: Ethan Dunham
** Date: 1/28/17
** Description: This is the implementation for the Game class.
*********************************************************************/

#include <iostream>
#include <string>
#include <unistd.h>//sleep
#include <cstdlib>
#include <time.h>
#include "Game.hpp"
#include "LoadedDie.hpp"

using std::cin;
using std::cout;
using std::endl;

//plays the game. It keeps track of the current score, the rolls, etc. It uses variables to 
//determine which function to call for each die and eventually outputs the winner.
void Game::playGame()
{
	Die *p1Die;
	if (p1Loaded == 'Y')
	{
		p1Die = new LoadedDie(p1Sides);
	}
	else
	{
		p1Die = new Die(p1Sides);
	}

	Die *p2Die;
	if (p2Loaded == 'Y')
	{
		p2Die = new LoadedDie(p2Sides);
	}
	else
	{
		p2Die = new Die(p2Sides);
	}

	for (int count = 0; count < turns; count++)
	{
		sleep(3);
		cout << std::string(100, '\n');//creates a nice menu look without clutter.
		p1Roll = (*p1Die).getRoll();
		cout << "The human rolled a " << p1Roll << " using a "<< p1Sides << " sided die." << endl;

		p2Roll = (*p2Die).getRoll();
		cout << "The computer rolled a " << p2Roll << " using a " << p2Sides << " sided die." << endl;

		if (p1Roll > p2Roll)
		{
			p1Score++;
			cout << "The human won." << endl;
		}
		else if (p1Roll < p2Roll)
		{
			p2Score++;
			cout << "The computer won." << endl;
		}
		else
		{
			cout << "This round was a draw." << endl;
		}
		cout << "The current score is:" << endl;
		cout << "Human: " << p1Score << endl;
		cout << "Computer: " << p2Score << endl;
	}
	cout << std::string(100, '\n');
	cout << "The final score is:" << endl;
	cout << "Human: " << p1Score << endl;
	cout << "The human used a "<< p1Sides << " sided die." << endl;
	cout << "Computer: " << p2Score << endl;
	cout << "The computer used a " << p2Sides << " sided die." << endl;
	if (p1Score > p2Score)
	{
		cout << "The human has won!" << endl;
	}
	else if (p2Score > p1Score)
	{
		cout << "The computer has won. :(" << endl;
		cout << "It probably cheated." << endl;
	}
	delete p1Die;
	delete p2Die;
}

//menu function sets all the relevant data for running the program 
//as well as calculated random values for those numbers not picked.
void Game::menu()
{
	int run = 0;
	while (run == 0)//loops while values are invalid and run has not been chosen yet
	{
		run = 0;
		int option;

		cout << std::string(100, '\n');

		do {//all do loops are validation of cin.fail()
			cout << "Option 1: How many sides for the human player? " << p1Sides << endl;
			cout << "Option 2: How many sides for the computer player? " << p2Sides << endl;
			cout << "Option 3: Is the human playing with loaded die? " << p1Loaded << endl;
			cout << "Option 4: Is the computer playing with loaded die? " << p2Loaded << endl;
			cout << "Option 5: How many rounds should there be? " << turns << endl;
			cout << "Option 6: Run program.*" << endl;
			cout << "*Values of 0 will be given random values when the program runs." << endl;
			cin >> option;
		} while (cinFail());

		switch (option)
		{
		case 1://P1
			do {
				cout << std::string(100, '\n');
				cout << "How many sides should the human player's die have?" << endl;
				cin >> p1Sides;
			} while (cinFail());
				while (p1Sides < 2 && p1Sides != 0)
				{
					do
					{
						cout << std::string(100, '\n');
						cout << "A die must have at least 2 sides (coin)." << endl;
						cout << "How many sides should the human player's die have?" << endl;
						cin >> p1Sides;
					} while (cinFail());
				}
			break;

		case 2://P2
			do {
				cout << std::string(100, '\n');
				cout << "How many sides should the computer player's die have?" << endl;
				cin >> p2Sides;
			} while (cinFail());
			while (p2Sides < 2 && p2Sides != 0)
			{
				do
				{
					cout << std::string(100, '\n');
					cout << "*****Invalid input*****" << endl;
					cout << "A die must have at least 2 sides (coin)." << endl;
					cout << "How many sides should the computer player's die have?" << endl;
					cin >> p2Sides;
				} while (cinFail());
			}
			break;

		case 3://P1 loaded
			do {
				cout << std::string(100, '\n');
				cout << "Is the human player playing with a loaded die? Y or N" << endl;
				cin >> p1Loaded;
			} while (cinFail());

			while (p1Loaded != '0' && p1Loaded !='N' && p1Loaded != 'Y' && p1Loaded != 'n' && p1Loaded != 'y')
			{
				do
				{
					cout << std::string(100, '\n');
					cout << "*****Invalid input*****" << endl;
					cout << "Is the human player playing with a loaded die? Y or N" << endl;
					cin >> p1Loaded;
				} while (cinFail());
			}

			if (p1Loaded == 'n')
			{
				p1Loaded = 'N';
			}

			if (p1Loaded == 'y')
			{
				p1Loaded = 'Y';
			}

			break;

		case 4://P2 loaded
			do {
				cout << std::string(100, '\n');
				cout << "Is the computer player playing with a loaded die? Y or N" << endl;
				cin >> p2Loaded;
			} while (cinFail());

			while (p2Loaded != '0' && p2Loaded != 'N' && p2Loaded != 'Y' && p2Loaded != 'n' && p2Loaded != 'y')
			{
				do
				{
					cout << std::string(100, '\n');
					cout << "*****Invalid input*****" << endl;
					cout << "Is the human player playing with a loaded die? Y or N" << endl;
					cin >> p2Loaded;
				} while (cinFail());
			}

			if (p2Loaded == 'n')
			{
				p2Loaded = 'N';
			}

			if (p2Loaded == 'y')
			{
				p2Loaded = 'Y';
			}

			break;

		case 5://Turns
			do {
				cout << std::string(100, '\n');
				if (turns < 0)//validation
				{
					cout << "Negative turns will not work. Please select a positive number or select 0 for random." << endl;
				}
				cout << "How many turns would you like the game to be?" << endl;
				cin >> turns;
			} while (cinFail() || turns<0);
			break;

		case 6://run
			run++;
		}
	}

	//sets random values for unchanged variables
	if (turns == 0)
	{
		turns = rand() % 100;
	}
	if (p1Sides == 0)
	{
		p1Sides = rand() % 100;
		if (p1Sides < 1)
		{
			p1Sides = 2;
		}
	}

	if (p2Sides == 0)
	{
		p2Sides = rand() % 100;
		if (p2Sides < 1)
		{
			p2Sides = 2;
		}
	}

	if (p1Loaded == '0')
	{
		int load = rand() % 2;

		if (load == 1)
		{
			p1Loaded = 'Y';
		}
		else
		{
			p1Loaded = 'N';
		}
	}

	if (p2Loaded == '0')
	{
		int load = rand() % 2;

		if (load == 1)
		{
			p2Loaded = 'Y';
		}
		else
		{
			p2Loaded = 'N';
		}
	}
	playGame();
}

//Stops endless loops from user entering incorrect information that breaks the program.
bool Game::cinFail()
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