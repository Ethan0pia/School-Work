/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Paper.hpp is the Paper class specification file.
* ***********************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"

class Paper: public Tool
{
public:
    Paper();
    Paper(int strength);
    int fight(Tool*);
	double findTempStrength(char t);
};
#endif