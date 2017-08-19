/**************************************************************************
** Program name: Verification functions
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the implementation file for verification functions
***************************************************************************/

#include "verification.hpp"
#include<iostream>

bool isLower(int a, int b)
{
	bool state = false;
	if (a < b)
	{
		state = true;
	}
	return state;
};

bool isHigher(int a, int b)
{
	bool state = false;
	if (a > b)
	{
		state = true;
	}
	return state;
};

bool isEqual(int a, int b)
{
	bool state = false;
	if (a == b)
	{
		state = true;
	}
	return state;
};

bool notLower0(int a)
{
	bool state = false;
	if (a > -1)
	{
		state = true;
	}
	return state;
};

bool greaterOrEqual(int a, int b)
{
	bool state = false;
	if (a >= b)
	{
		state = true;
	}
	return state;
};

bool lessOrEqual(int a, int b)
{
	bool state = false;
	if (a <= b)
	{
		state = true;
	}
	return state;
};

bool cinFail()
{
	bool state;//validates cin statements
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(300, '\n');
		std::cout << "****That is invalid input. Please try again.****" << std::endl;
		state = true;
	}
	else
	{
		state = false;
	}
	return state;
}