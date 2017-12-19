/************************************************************************
** Program name:RPG - final project
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the main for the final project, a vampire slayer
**				dungeon crawler RPG.
*************************************************************************/

#include"Space.hpp"
#include"ChestSquare.hpp"
#include"Square.hpp"
#include"DoorSquare.hpp"
#include"WallSquare.hpp"
#include"MonsterSquare.hpp"
#include"VampireSquare.hpp"
#include"TrapSquare.hpp"
#include "KeySquare.hpp"
#include "Player.hpp"
#include <iostream>
#include<string>
#include <stdlib.h> //srand, rand
#include <time.h> // time
using std::cout;
using std::cin;
using std::endl;
using std::string;

//stops endless loops on incorrect input
bool cinFail();
//displays the map, cheater
void displayMap(char*);
//fights
void fight(Space*, Player*);

int main()
{
	srand(time(NULL));

	int turns = 35;
	//7 empty spaces
	Space *empty1 = new Square();
	Space *empty2 = new Square();
	Space *empty3 = new Square();
	Space *empty4 = new Square();
	Space *empty5 = new Square();
	Space *empty6 = new Square();
	Space *empty7 = new Square();
	//3 monster spaces
	Space *mob1 = new MonsterSquare(1);
	Space *mob2 = new MonsterSquare(2);
	Space *mob3 = new MonsterSquare(3);
	//1 vampire space
	Space *vamp = new VampireSquare();
	//2 traps
	Space *trap1 = new TrapSquare();
	Space *trap2 = new TrapSquare();
	//1 key
	Space *key = new KeySquare();
	//1 door
	Space *door = new DoorSquare();
	//1 wall
	Space *wall = new WallSquare();
	//1 chest
	Space *chest = new ChestSquare();
	//1 pointer to current player location
	Space *p1 = empty1;
	//pointers up, down, left, right
	//initializing the board.
	empty1->setPointers(wall, empty2, wall, wall);
	empty2->setPointers(empty1, empty3, wall, wall);
	empty3->setPointers(empty2, mob1, trap1, wall);
	trap1->setPointers(wall, wall, mob2, empty3);
	mob2->setPointers(wall, wall, chest, trap1);
	chest->setPointers(wall, wall, wall, mob2);
	mob1->setPointers(empty3, empty4, wall, wall);
	empty4->setPointers(mob1, door, wall, empty5);
	empty5->setPointers(wall, wall, empty4, trap2);
	trap2->setPointers(mob3, wall, empty5, wall);
	mob3->setPointers(key, trap2, wall, wall);
	key->setPointers(wall, mob3, wall, wall);
	door->setPointers(empty4, empty6, wall, wall);
	empty6->setPointers(door, empty7, wall, wall);
	empty7->setPointers(empty6, vamp, wall, wall);
	vamp->setPointers(empty7, wall, wall, wall);
	Player *play1 = new Player();
	//cheating map
	char board[11][8] = { ' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', 'P', 'W', ' ', ' ',
						  'W', 'W', 'W', 'W', ' ', 'W', 'W', 'W',
						  'W', 'C', 'M', 'T', ' ', 'W', 'K', 'W',
						  'W', 'W', 'W', 'W', 'M', 'W', 'M', 'W',
						  ' ', ' ', ' ', 'W', ' ', ' ', 'T', 'W',
						  ' ', ' ', ' ', 'W', 'D', 'W', 'W', 'W',
						  ' ', ' ', ' ', 'W', ' ', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', ' ', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', 'V', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', }; 

	char board2[11][8] = { ' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', ' ', 'W', ' ', ' ',
					   	  'W', 'W', 'W', 'W', ' ', 'W', 'W', 'W',
						  'W', 'C', 'M', 'T', ' ', 'W', 'K', 'W',
						  'W', 'W', 'W', 'W', 'M', 'W', 'M', 'W',
						  ' ', ' ', ' ', 'W', ' ', ' ', 'T', 'W',
						  ' ', ' ', ' ', 'W', 'D', 'W', 'W', 'W',
						  ' ', ' ', ' ', 'W', ' ', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', ' ', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', 'V', 'W', ' ', ' ',
						  ' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', };

	char board3[11][8] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', 'P', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };

	char enter[100];
	int option;
	do {
		cout << "              Welcome to vampire slayer, a simple game by Ethan Dunham." << endl;
		cout << "This game is a top down set map that does not turn based on the direction the player is moving." << endl;
		cout << "	  Up, down, left, and right, will always be the same direction on the map." << endl;
		cout << "		IE if you go left and then right, you will be back in the same space." << endl << endl;
		cout << "            In this game, you will find your way around a simple dungeon." << endl;
		cout << "             You will run into monsters, traps, locked doors, and chests." << endl;
		cout << "You will need to find the key within 35 turns or you will be traped in the dungeon forever." << endl;
		cout << "           You are given 5 potions. They will heal you back to max health." << endl;
		cout << "   Find the key to open the door. Then fight the vampire for your chance at glory." << endl << endl << endl;

		cout << "            You play an adventurer named John Jacob Jingle Heimer Schmidt." << endl;
		cout << "                You are the Fifth Earl of Sandwich and Duke of Molasas." << endl;
		cout << "   In an ironic turn of events, The Earl of Sandwich owes fealty to the Duke of Molasas." << endl;
		cout << "		Thus, if you, the Duke of Molasas, run into any problems." << endl;
		cout << "	You may call on yourself, the Earl of Sandwich, to render yourself aid." << endl;
		cout << "		  You are then duty bound to assist yourself." << endl;
		cout << "Other than the company of the Earl of Sandwich, you find yourself alone in a scary dungeon." << endl << endl;
		cout << "Press enter to continue:";
		cin.getline(enter, 99);
	} while (cinFail());

	while (play1->getPoints() != 0)
	{
		do {
			cout << std::string(100, '\n');
			cout << "First, you must choose the strengths of your character." << endl;
			cout << "You have " << play1->getPoints() << " attribute points remaining to allocate." << endl;
			cout << "Enter 1: Increase Strength/HP by 1. Effects the amount of damage you can take before you die: " << play1->getStr() << endl;
			cout << "Enter 2: Increase dexterity by 1. Effects the amount of damage you take from traps: "<< play1->getDex() << endl;
			cout << "Enter 3: Increase number of die by 1. Effects the amount of die you roll for attack and defense: "<< play1->getDie() << endl;
			cout << "Enter 4: Increase number of die sides by 1. Effects the amount of sides on each die you roll: "<< play1->getSides() << endl;
			cout << "Enter 5: Increase number of defense by 1. Decreases the amount of damage you take from enemies: "<< play1->getDef() << endl;
			cin >> option;
		} while (cinFail() || option < 0 || option>5);
		switch (option)
		{
		case 1:
			play1->addStr();
			break;
		case 2:
			play1->addDexterity();
			break;
		case 3:
			play1->addDie();
			break;
		case 4:
			play1->addSides();
			break;
		case 5:
			play1->addDefense();
			break;
		}
	}
	int i = 0;
	int x = 1;
	int y = 4;
	p1->action();
	while (i < turns && play1->getStr() > 0 && vamp->getStr() > 0)
	{
		Space *temp = p1;
		do {
			if (option != 9)
			{
				displayMap(*board3);
			}
			cout << "Turn: " << i+1 << " of " << turns << endl;
			cout << "Enter 1: Move up" << endl;
			cout << "Enter 2: Move down" << endl;
			cout << "Enter 3: Move left" << endl;
			cout << "Enter 4: Move right" << endl;
			cout << "Enter 5: Display inventory" << endl;
			cout << "Enter 6: Use potion" << endl;
			cout << "Enter 7: Display inventory" << endl;
			cout << "Enter 8: Display Strength/HP" << endl;
			cout << "Enter 9: *Cheat: Display complete map" << endl;
			cin >> option;
		} while (cinFail() || option < 0 || option>9);
		cout << std::string(100, '\n');
		switch (option)
		{
		case 1:
			p1 = p1->getDirection('u',p1);
			if (p1 != temp)
			{
				board[x][y] = board2[x][y];
				board3[x][y] = board2[x][y];
				x--;
				board[x][y] = 'P';
				board3[x][y] = 'P';
			}
			else
			{
				board3[x-1][y] = 'W';
			}
			break;
		case 2:
			p1 = p1->getDirection('d', p1);
			if (p1 != temp)
			{
				board[x][y] = board2[x][y];
				board3[x][y] = board2[x][y];
				x++;
				board[x][y] = 'P';
				board3[x][y] = 'P';
			}
			else
			{
				if (x == 5 && y == 4)
				{
					board3[x + 1][y] = 'd';
				}
				else
				{
					board3[x + 1][y] = 'W';
				}
			}
			break;
		case 3:
			p1 = p1->getDirection('l', p1);
			if (p1 != temp)
			{
				board[x][y] = board2[x][y];
				board3[x][y] = board2[x][y];
				y--;
				board[x][y] = 'P';
				board3[x][y] = 'P';
			}
			else
			{
				board3[x][y-1] = 'W';
			}
			break;
		case 4:
			p1 = p1->getDirection('r', p1);
			if (p1 != temp)
			{
				board[x][y] = board2[x][y];
				board3[x][y] = board2[x][y];
				y++;
				board[x][y] = 'P';
				board3[x][y] = 'P';
			}
			else
			{
				board3[x][y+1] = 'W';
			}
			break;
		case 5:
			play1->displayInv();
			break;
		case 6:
			play1->usePotion();
			break;
		case 7:
			play1->displayInv();
		case 8:
			cout << "Current HP is:" << play1->getStr() << endl;
			break;
		case 9:
			displayMap(*board);
			break;
		}
		if (temp != p1)
		{
			i++;
			int act = p1->action();
			//monster to fight
			if (act == 3)
			{
				fight(p1, play1);
			}
			if (act == 4)
			{
				play1->addModifier();
			}
			if (act == 5)
			{
				door->setKey();
				play1->addBackpack("key", 1);
			}
			if (act == 6)
			{
				int hit;
				hit = p1->trap(play1->getDex());
				play1->damage(hit);
				cout << "Current HP is:" << play1->getStr() << endl;
			}
		}

	}
	cout << std::string(100, '\n');
	if (play1->getStr() == 0)
	{
		cout << "Oh dear, you died." << endl;
	}
	if (vamp->getStr() == 0)
	{
		cout << "You killed the vampire. Good job." << endl;
	}
	if (i == 35)
	{
		cout << "You ran out of time. You are now stuck in the dungeon forever, sorry." << endl;
	}
	//delete all rooms and such
	delete empty1;
	delete empty2;
	delete empty3;
	delete empty4;
	delete empty5;
	delete empty6;
	delete empty7;
	delete mob1;
	delete mob2;
	delete mob3;
	delete vamp;
	delete trap1;
	delete trap2;
	delete key;
	delete door;
	delete wall;
	delete chest;
	delete play1;
	return 0;
}

void displayMap(char *board)
{
	cout << endl;
	for (int i = 0; i < 11; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			cout << board[i*8+y]<<" ";
		}
		cout << endl;
	}
	cout << "P = Player" << endl;
	cout << "W = Wall" << endl;
	cout << "M = Monster" << endl;
	cout << "T = Trap" << endl;
	cout << "D = Door" << endl;
	cout << "C = Chest" << endl;
	cout << "K = Key" << endl;
	cout << "V = Vampire" << endl;
	cout << endl;
}

void fight(Space* mob, Player* player)
{
	int option;
	if (mob->getStr() > 0)
	{
		while (player->getStr() > 0 && mob->getStr() > 0)
		{
			do {
				cout << "Your current HP is:" << player->getStr() << endl;
				cout << "Enter 1: Attack." << endl;
				cout << "Enter 2: Drink potion." << endl;
				cout << "Enter 3: Display Inventory" << endl;
				cin >> option;
			} while (cinFail() || option > 3 || option < 0);
			if (option == 1)
			{
				int playerAtt = player->fight();
				mob->defend(playerAtt);
				int mobAtt = mob->fight();
				player->defend(mobAtt);
			}
			if (option == 2)
			{
				player->usePotion();
				int mobAtt = mob->fight();
				player->defend(mobAtt);
			}
			if (option == 3)
			{
				player->displayInv();
			}

		}
		if (mob->getStr() < 0)
		{
			cout << "You killed the monster. Good job." << endl;
		}
	}
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