/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Tool.cpp is the Tool class implementation file.
* ***********************************************************/

#include "Tool.hpp"

Tool::Tool()
{
    setStrength(1);
}
char Tool::getType()
{
    return type;
}
int Tool::getStrength()
{
    return strength;
}
void Tool::setStrength(int strengthIn)
{
    strength = strengthIn;
}
