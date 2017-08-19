/**************************************************************
* Authors: Lindsey Bunte, Ethan Dunham, Bryan Fishback, Marisa Rea, Dean Ohashi, James Whiteley IV, Kyle Wollman
* Date: 2/13/2017
* Description: Group Project
* Tool.hpp is the Tool class specification file.
* ***********************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

class Tool {
protected:
    double strength;
    char type;
public:
    Tool();
    void setStrength(int);
    int getStrength();
    char getType();
    virtual int fight(Tool*) = 0;
    virtual ~Tool(){}
};
#endif
