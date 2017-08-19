/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the implementation file for the Building class.
*********************************************************************/

#include"Building.hpp"
#include<iostream>

//building constructor
Building::Building(string name, string _address, int footage)
{
	buildingName = name;
	address = _address;
	squareFT = footage;
}

//returns the name for comparison and validation
string Building::GetName()
{
	return buildingName;
}

//prints the info about the building.
void Building::DisplayInfo()
{
	std::cout << "Building's Name:" << buildingName << "     Building's Address:" << address << "     Square Footage:" << squareFT << std::endl;
}