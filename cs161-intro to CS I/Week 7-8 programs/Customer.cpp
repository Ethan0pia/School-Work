/*******************************************************************************************
** Author: Ethan Dunham
** Date: 11/24/16
** Description: This is the implementation file for the Customer class.
*******************************************************************************************/

#include "Customer.hpp"
#include<string>
#include <vector>

/******************************************************************************************
** Description: This is the constructor for the customer object.
********************************************************************************************/
Customer::Customer(std::string n, std::string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

/******************************************************************************************
** Description: Returns the customer's ID number.
********************************************************************************************/
std::string Customer::getAccountID()
{
	return accountID;
}

/******************************************************************************************
** Description: Returns the customer's cart.
********************************************************************************************/
std::vector<std::string> Customer::getCart()
{
	return cart;
}

/******************************************************************************************
** Description: Adds a product to the card of the customer.
********************************************************************************************/
void Customer::addProductToCart(std::string itemNum)
{
	cart.push_back(itemNum);
}

/******************************************************************************************
** Description: Returns if the person is a premium member or not.
********************************************************************************************/
bool Customer::isPremiumMember()
{
	return premiumMember;
}

/******************************************************************************************
** Description: This function empties the Customer's cart.
********************************************************************************************/
void Customer::emptyCart()
{
	cart.resize(0);
}

