/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the class for the player class.
*************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<iostream>
#include<string>

class Player
{
private:
	int points = 4;
	int strength = 10;
	int maxStr = 10;
	int die = 1;
	int sides = 4;
	int modifier = 0;
	int dexterity = 1;
	int defense = 1;
	std::string backpack[3] = { "Potion","Empty","Empty" };
	int quantity[3] = { 5,0,0 };
public:
	Player();
	//all adds increment the value by 1 and decrement points.
	void addStr();
	void addDie();
	void addSides();
	void addModifier();
	void addDexterity();
	void addDefense();
	int fight();
	void defend(int);
	int getDex();
	int getDie();
	int getSides();
	int getDef();
	int getPoints();
	int getStr();
	void damage(int);
	void usePotion();
	void displayInv();
	void addBackpack(std::string, int);
};


#endif