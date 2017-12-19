/*********************************************************************
** Program name:Shopping List
** Author: Ethan Dunham
** Date: 2/04/17
** Description: This is the header file for the List class.
*********************************************************************/

#ifndef List_HPP
#define List_HPP
#include<string>
#include "Item.hpp"
using std::string;

class List
{
private:
	Item **listArray;
	Item **oldListArray;
	int currentArraySize = 4;
	int currentItems=0;
public:
	//constructor for the list.
	List();
	//adds item to the list by adding to the array of pointers to Item objects.
	void addToList(string, string, int, double);
	//deletes from the list by creating a new array without the item to delete and deletes the item.
	//returns true if deleted.
	bool listDelete(string, int);
	//prints out the board for easy viewing.
	void display();
	//deletes the lists
	void exit();
};
#endif
