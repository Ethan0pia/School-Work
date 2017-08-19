/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Rock.cpp is the Rock class implementation file.
* ***********************************************************/

#include "Rock.hpp"

Rock::Rock()
{
    setStrength(1);
    type = 'r';
}

Rock::Rock(int strengthIn)
{
    setStrength(strengthIn);
    type = 'r';
}

/************************************************************
** Description: Fight Function that takes a tool object and
** returns an integer that represents the winner. This
** function also sets this object's strength based on the
** type of object passed into and returned by the
** findTempStrength function.
*************************************************************/
int Rock::fight(Tool* ai)
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
** Rock's strength is based on the type of object passed into 
** the function. The function returns a double that represents 
** the temporary Rock strength value. 
*************************************************************/
double Rock::findTempStrength(char t)
{
	double tempStrength = 1;
	
	 if (t == 's')
    {
        tempStrength = strength * 2;
    }
    else if (t == 'p')
    {
        tempStrength = strength / 2;
    }
	else
	{
		tempStrength = strength;
	}
	return tempStrength;
}