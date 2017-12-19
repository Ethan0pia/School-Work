/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Scissors.cpp is the Scissors class implementation file.
* ***********************************************************/

#include "Scissors.hpp"

Scissors::Scissors()
{
    setStrength(1);
    type = 's';
}

Scissors::Scissors(int strengthIn)
{
    setStrength(strengthIn);
    type = 's';
}

/************************************************************
** Description: Fight Function that takes a tool object and
** returns an integer that represents the winner. This
** function also sets this object's strength based on the
** type of object passed into and returned by the
** findTempStrength function.
*************************************************************/
int Scissors::fight(Tool* ai)
{
	char type = ai->getType();
    double tempStrength = findTempStrength(type);
	int result;
	
    if (ai->getStrength() == tempStrength)
    {
        result = 0;
    }
    if (ai->getStrength() < tempStrength)
    {
        result = 1;
    }
    if (ai->getStrength() > tempStrength)
    {
        result = 2;
    }
	return result;
}

/************************************************************
** Description: findTempStrength is a function that takes a 
** character which represents the computer's tool type. The 
** Scissor's strength is based on the type of object passed into 
** the function. The function returns a double that represents 
** the temporary Scissors strength value. 
*************************************************************/
double Scissors::findTempStrength(char t)
{
	double tempStrength = 1;
	if (t == 'p')
    {
        tempStrength = strength * 2;
    }
    else if (t == 'r')
    {
        tempStrength = strength / 2;
    }
	else
	{
		tempStrength = strength;
	}
	
	return tempStrength;
}
