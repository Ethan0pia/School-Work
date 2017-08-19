/*********************************************************************
** Program name:Shopping List
** Author: Ethan Dunham
** Date: 2/04/17
** Description: This is the header file for the Item class.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include<string>

using std::string;

class Item
{
private:
	double itemPrice;
	string itemName;
	string itemType;
	int quantity;

public:
	Item();
	//constructor for class.
	Item(string, string, int, double);
	double getItemPrice();
	string getItemName();
	string getItemType();
	int getItemQuantity();
	void setItemQuantity(int);
};
#endif
