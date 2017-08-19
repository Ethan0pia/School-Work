/************************************************************************
** Program name:RPG
** Author: Ethan Dunham
** Date: 3/9/17
** Description: This is the class for the player class.
*************************************************************************/

#include<iostream>
#include"Player.hpp"


Player::Player()
{}

void Player::addStr()
{
	strength++;
	maxStr++;
	points--;
}

void Player::addDie()
{
	die++;
	points--;
}

void Player::addSides()
{
	sides++;
	points--;
}

void Player::addModifier()
{
	modifier += 5;
}

void Player::addDexterity()
{
	dexterity++;
	points--;
}

void Player::addDefense()
{
	defense++;
	points--;
}

int Player::fight()
{
	int roll=0;
	for (int i = 0; i < die; i++)
	{
		roll += rand() % sides;
	}
	return roll+modifier;
}

void Player::defend(int hit)
{
	int roll=0;
	for (int i = 0; i < die; i++)
	{
		roll += rand() % sides;
	}
	if (hit > roll)
	{
		hit = hit - defense;
	}
	if (hit < 0|| hit < roll)
	{
		hit = 0;
	}
	if (hit > 0)
	{
		strength -= hit;
	}
	std::cout << "You were hit for " << hit << " damage." << std::endl;
}

int Player::getDex()
{
	return dexterity;	
}

int Player::getPoints()
{
	return points;
}

int Player::getStr()
{
	return strength;
}

void Player::usePotion()
{
	if (quantity[0] > 0)
	{
		std::cout << "You drink a potion. You regain all your lost HP. You are back up to " << strength << " HP." << std::endl;
		strength = maxStr;
		quantity[0]--;
	}
	else
	{
		std::cout << "You rummage around in your backpack only to discover in feat that..." << std::endl;
		std::cout << "You do not have any potions left." << std::endl;
	}
}

void Player::displayInv()
{
	std::cout << "Your inventory contains:" << std::endl;
	std::cout << backpack[0] << ": " << quantity[0] << std::endl;
	std::cout << backpack[1] << ": " << quantity[1] << std::endl;
	std::cout << backpack[2] << ": " << quantity[2] << std::endl;
}

int Player::getDie()
{
	return die;
}

int Player::getSides()
{
	return sides;
}

int Player::getDef()
{
	return defense;
}

void Player::damage(int hit)
{
	std::cout << "You were hit for " << hit << " damage." << std::endl;
	strength = strength - hit;
}

void Player::addBackpack(std::string item, int quant)
{
	if (backpack[1] == "Empty")
	{
		backpack[1] = item;
		quantity[1] = quant;
	}
	else if (backpack[2] == "Empty")
	{
		backpack[2] = item;
		quantity[2] = quant;
	}
}