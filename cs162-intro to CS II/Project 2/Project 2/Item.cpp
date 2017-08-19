/*********************************************************************
** Program name:Shopping List
** Author: Ethan Dunham
** Date: 2/04/17
** Description: This is the implementation file for the Item class.
*********************************************************************/
#include "Item.hpp"
#include<string>
using std::string;

Item::Item()
{
	itemName = "";
	itemType = "";
	itemPrice=0;
	quantity=0;
}

Item::Item(string itemName, string itemType, int quantity, double itemPrice)
{
	this->itemName = itemName;
	this->itemType = itemType;
	this->itemPrice= itemPrice;
	this->quantity = quantity;
}

double Item::getItemPrice()
{
	return itemPrice;
}

string Item::getItemName()
{
	return itemName;
}

string Item::getItemType()
{
	return itemType;
}
int Item::getItemQuantity()
{
	return quantity;
}
void Item::setItemQuantity(int quantity)
{
	this->quantity = quantity;
}
