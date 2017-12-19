/*************************************************************************
** Program name: RPG Game
** Author: Ethan Dunham
** Date: 2/11/17
** Description: This is the implementation file for main and menu.
**************************************************************************/


#include<iostream>
#include<string>
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include"Queue.hpp"

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

//lets the user pick the fighters. Then has them fight.
void menu()
{
	int size;
	char disp;
	do {
		cout << "Would you like every round to be displayed? Enter 'y' for yes." << endl;
		cin >> disp;
	} while (cinFail());

	do {
		cout << "How many fighters would you like each player to have?" << endl;
		cin >> size;
	} while (cinFail());
	Queue game(size, disp);
	int option;
	int player = 1;
	int character = 0;

	while (player < 3)
	{
		cout << std::string(5, '\n');
		character++;
		char name[100];

		do {//all do loops are validation of cin.fail()
			cout << "Please pick fighter #" << character << " for player " << player << "." <<endl;
			cout << "Option 1: Vampire: Suave, debonair, but vicious and surprisingly resilient!" << endl;
			cout << "Option 2: Barbarian: Big sword, big muscles, bare torso." << endl;
			cout << "Option 3: Blue Men: A mob of 6\" attackers." << endl;
			cout << "Option 4: Medusa: Scrawny lady with snakes for hair. Just do not look at her!" << endl;
			cout << "Option 5: Harry Potter: Magician with a penchant for trouble." << endl;
			cin >> option;
		} while (cinFail() || option < 1 || option > 5);

		do{
			cout << "What is the fighter's name?" << endl;
			std::cin.clear();
			std::cin.ignore(300, '\n');
			cin.getline(name, 100);
		} while (cinFail());

		game.addBack(option, name, player);
		
		if (character == size)
		{
			player++;
			character = 0;
		}
	}
	game.fight();
	game.clear();
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