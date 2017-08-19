/*******************************************************************************************
** Author: Ethan Dunham
** Date: 11/24/16
** Description: This is the implementation file for the Store class.
*******************************************************************************************/

#include"Store.hpp"
#include"Product.hpp"
#include"Customer.hpp"
#include<vector>
#include<string>
#include<iostream>
#include <iomanip>

/******************************************************************************************
** Description: Adds a product to the inventory
********************************************************************************************/
void Store::addProduct(Product* p)
{
	inventory.push_back(p);
}

/******************************************************************************************
** Description: Adds a member to the list of members.
********************************************************************************************/
void Store::addMember(Customer* c)
{
	members.push_back(c);
}

/******************************************************************************************
** Description: This function returns the product object for an id number.
********************************************************************************************/
Product* Store::getProductFromID(std::string search)
{
	int lengthOfVector = inventory.size();//gets length of current inventory
	//checks each item in inventory and tries to match the product id.
	for (int i = 0; i < lengthOfVector; i++)
	{
		//returns the found product or NULL if it did not find anything.
		std::string idCode = inventory[i]->getIdCode();
		if (search == idCode)
			return inventory[i];
		if (i==lengthOfVector-1)
			return NULL;
	}
}

/******************************************************************************************
** Description: This function returns the customer object for an id number.
********************************************************************************************/
Customer* Store::getMemberFromID(std::string search)
{
	int lengthOfVector = members.size();
	//checks each customer and tries to match the id.
	for (int i = 0; i < lengthOfVector; i++)
	{
		std::string idCode = members[i]->getAccountID();
		if (search == idCode)
			return members[i];
		if (i == lengthOfVector - 1)
			return NULL;
	}
}

/******************************************************************************************
** Description: This function searches products for a certain string.
********************************************************************************************/
void Store::productSearch(std::string search)
{
	int lengthOfVector = inventory.size();

	std::string search2 = search;

	if (search[0] > 96 && search[0] < 123)//converts 1st letter to uppercase if lowercase.
		search2[0] = search[0] - 32;

	else if (search[0] > 64 && search[0] < 91)//converts 1st letter to lowercase if uppercase.
		search2[0] = search[0] + 32;

	for (int i = 0; i < lengthOfVector; i++)
	{
		bool print = false;

		//searches the id, title, and description for the provided string in the vector of products.
		std::string idCode = inventory[i]->getIdCode();
		int length = idCode.length();
		if (idCode.find(search) < length || idCode.find(search2) < length)
			print = true;

		std::string title = inventory[i]->getTitle();
		int lengt = title.length();
		if (title.find(search) < lengt || title.find(search2) < lengt)
			print = true;

		std::string description = inventory[i]->getDescription();
		int leng = description.length();
		if (description.find(search) < leng || description.find(search2) < leng)
			print = true;

		double price = inventory[i]->getPrice();

		if (print)//prints the found items.
		{
			std::cout << std::endl;
			std::cout << title << std::endl;
			std::cout << "ID code: " << idCode << std::endl;
			std::cout << "Price: $" << price << std::endl;
			std::cout << description << std::endl;
			std::cout << std::endl;
		}
	}
}

/******************************************************************************************
** Description: This function adds a specified item to the customer's cart.
********************************************************************************************/
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
	Customer* person = getMemberFromID(mID);
	Product* item = getProductFromID(pID);

	if (item == NULL)
		std::cout << "Product #" << pID << " not found." << std::endl;
	if (person == NULL)
		std::cout << "Member #" << mID << " not found." << std::endl;

	if (item != NULL && person != NULL)
	{

		int quantity = item->getQuantityAvailable();
		if (quantity > 0)
			person->addProductToCart(pID);

		else
			std::cout << "Sorry, product #" << pID << " is currently out of stock." << std::endl;
	}
}

/******************************************************************************************
** Description: This function adds the prices of the items in the cart together and
**				calculated shipping.
********************************************************************************************/
void Store::checkOutMember(std::string mID)
{
	double shipping = 0;
	double total = 0;
	Customer* customr = getMemberFromID(mID);

	if (customr != NULL)
	{
		std::vector<std::string> cart = customr->getCart();//sets a vector of cart to the customer's cart.
		int cartLength = cart.size();

		if (cartLength < 1)//if 0 items in vector
			std::cout << "There are no items in the cart." << std::endl;
		else
		{
		for (int i = 0; i < cartLength; i++)
				{
					Product* item = getProductFromID(cart[i]);//finds the product.
					std::string title = item->getTitle();

					if (item->getQuantityAvailable() < 1)//is product sold out
						std::cout << "Sorry, product #" << item->getIdCode() << ", \"" 
						<< item->getTitle() << "\", is no longer available."<< std::endl;

					else
					{
						//prints the price of the item
						std::cout << title << "- $" << item->getPrice() << std::endl;
						total = total + item->getPrice();//adds price to item
						item->decreaseQuantity();//decreases item
					}

				}

				std::cout << std::fixed << std::showpoint;
				std::cout << std::setprecision(2);
				std::cout << "Subtotal: $" << total << std::endl;//prints total

				if (!customr->isPremiumMember())
					shipping = 0.07*total;

				std::cout << std::fixed << std::showpoint;
				std::cout << std::setprecision(2);
				std::cout << "Shipping Cost: $" << shipping << std::endl;//prints shipping price

				total = total + shipping;

				std::cout << std::fixed << std::showpoint;
				std::cout << std::setprecision(2);
				std::cout << "Total: $" << total << std::endl;//prints total+shipping

				customr->emptyCart();//empties the cart.
			}

		}

		if (customr == NULL)
			std::cout << "Member #" << mID << " not found." << std::endl;
}


/*
int main()
{
	Store st1;
	std::string productId1 = "9984";
	std::string productId2 = "9985";
	std::string itemName1 = "Red Hat";
	std::string ItemName2 = "Clifford the Big Red Dog";
	std::string description1 = "This is a red hat.";
	std::string description2 = "This is a giant stuffed red dog.";
	double price1 = 9.99;
	double price2 = 29.99;
	int quant1 = 5;
	int quant2 = 3;
	std::string name1 = "Ethan Dunham";
	std::string name2 = "Alise Vedrenne";
	std::string memID1 = "2322";
	std::string memID2 = "2323";
	bool prem1 = true;
	bool prem2 = false;

	Product* p1 = new Product(productId1, itemName1, description1, price1, quant1);
	Product* p2= new Product(productId2, ItemName2, description2, price2, quant2);
	Customer* c1= new Customer(name1, memID1, prem1);
	Customer* c2= new Customer(name2, memID2, prem2);

	st1.addProduct(p1);
	st1.addProduct(p2);
	st1.addMember(c1);
	st1.addMember(c2);

	std::string mID = "2323";
	std::string pID = "9985";
	Customer* custom = st1.getMemberFromID(mID);
	std::string str = "red";
	st1.productSearch(str);
	Product* prod = st1.getProductFromID(pID);
	std::cout << prod->getDescription() << std::endl;
	st1.addProductToMemberCart(pID, mID);
	st1.addProductToMemberCart(pID, mID);
	st1.addProductToMemberCart(pID, mID);
	st1.addProductToMemberCart(pID, mID);
	st1.addProductToMemberCart(pID, mID);
	pID = "9987";
	mID = "2325";
	st1.addProductToMemberCart(pID, mID);
	pID = "9984";
	mID = "2323";
	st1.checkOutMember("2354");
	st1.addProductToMemberCart(pID, mID);
	st1.checkOutMember(mID);
	
	delete p1;
	delete p2;
	delete c1;
	delete c2;
		
	return 0;
}
*/