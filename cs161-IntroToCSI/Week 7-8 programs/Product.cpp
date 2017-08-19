/*******************************************************************************************
** Author: Ethan Dunham
** Date: 11/24/16
** Description: This is the implementation file for the Product class.
*******************************************************************************************/

#include "Product.hpp"
#include <string>

/******************************************************************************************
** Description: This is the constructor for the product object.
********************************************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/******************************************************************************************
** Description: Returns the id code of the item.
********************************************************************************************/
std::string Product::getIdCode()
{
	return idCode;
}

/******************************************************************************************
** Description: Returns the title of the item.
********************************************************************************************/
std::string Product::getTitle()
{
	return title;
}

/******************************************************************************************
** Description: Returns the description of the item.
********************************************************************************************/
std::string Product::getDescription()
{
	return description;
}

/******************************************************************************************
** Description: Returns the price of the item.
********************************************************************************************/
double Product::getPrice()
{
	return price;
}

/******************************************************************************************
** Description: Returns the current availability of the item.
********************************************************************************************/
int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

/******************************************************************************************
** Description: Decreases the current availability by 1.
********************************************************************************************/
void Product::decreaseQuantity()
{
	quantityAvailable--;
}
