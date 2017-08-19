/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for main and menu.
**************************************************************************/

#include"Medusa.hpp"
#include"Barbarian.hpp"
#include"Creature.hpp"
#include"BlueMen.hpp"
#include"HarryPotter.hpp"
#include"Vampire.hpp"
#include<iostream>
#include<string>
#include <stdlib.h> //srand, rand
#include <time.h> // time

using std::cin;
using std::cout;
using std::endl;

void menu();
bool cinFail();
//calls the menu and initiates srand.
int main()
{
	srand(time(NULL));
	menu();
	return 0;
}
//lets the user pick the 2 fighters. Then has them fight.
void menu()
{
	Creature *p1 = NULL;
	Creature *p2 = NULL;
	int option;
	int player = 1;

	while (player != 3)
	{
		cout << std::string(5, '\n');
		do {//all do loops are validation of cin.fail()
			cout << "Please pick fighter #" << player << "." << endl;
			cout << "Option 1: Vampire: Suave, debonair, but vicious and surprisingly resilient!" << endl;
			cout << "Option 2: Barbarian: Big sword, big muscles, bare torso." << endl;
			cout << "Option 3: Blue Men: A mob of 6\" attackers." << endl;
			cout << "Option 4: Medusa: Scrawny lady with snakes for hair. Just do not look at her!" << endl;
			cout << "Option 5: Harry Potter: Magician with a penchant for trouble." << endl;
			cin >> option;
		} while (cinFail() || option < 1 || option>5);

		switch (option)
		{
		case 1://Vamp
			if (player == 1)
			{
				p1 = new Vampire();
			}
			else
			{
				p2 = new Vampire();
			}
			break;

		case 2://Barb
			if (player == 1)
			{
				p1 = new Barbarian();
			}
			else
			{
				p2 = new Barbarian();
			}
			break;

		case 3://Blue Men
			if (player == 1)
			{
				p1 = new BlueMen();
			}
			else
			{
				p2 = new BlueMen();
			}
			break;

		case 4://Medusa
			if (player == 1)
			{
				p1 = new Medusa();
			}
			else
			{
				p2 = new Medusa();
			}
			break;

		case 5://Harry Potter
			if (player == 1)
			{
				p1 = new HarryPotter();
			}
			else
			{
				p2 = new HarryPotter();
			}
			break;
		}
		player++;
	}

	int currentPlayer;
	int attRoll;
	int defRoll;
	currentPlayer = rand() % 2 + 1;

	do
	{
		if (currentPlayer == 1)
		{
			attRoll = p1->rollAttack();
			p2->rollDefence(attRoll);
			currentPlayer = 2;
		}
		else
		{
			attRoll = p2->rollAttack();
			p1->rollDefence(attRoll);
			currentPlayer = 1;
		}
	} while (!p1->death() && !p2->death());
	if (p1->death())
	{
		cout << "Player 1 is dead." << endl;
	}
	else
	{
		cout << "Player 2 is dead." << endl;
	}
	delete p1;
	delete p2;
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