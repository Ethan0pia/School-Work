/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the header for the Building class.
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP
#include<string>
using std::string;

class Building
{
private:
	string buildingName;
	string address;
	int squareFT;

public:
	//constructor
	Building(string, string, int);
	//returns the name of the building
	string GetName();
	//prints the info for the building
	void DisplayInfo();
};

#endif