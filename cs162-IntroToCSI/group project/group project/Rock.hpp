/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Rock.hpp is the Rock class specification file.
* ***********************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"

class Rock : public Tool
{
public:
    Rock();
    Rock(int strength);
    int fight(Tool*);
	double findTempStrength(char t);
};
#endif