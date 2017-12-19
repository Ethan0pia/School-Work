/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Scissors.hpp is the Scissors class specification file.
* ***********************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"


class Scissors: public Tool
{
public:
    Scissors();
    Scissors(int strength);
    int fight(Tool*);
	double findTempStrength(char t);
};
#endif
