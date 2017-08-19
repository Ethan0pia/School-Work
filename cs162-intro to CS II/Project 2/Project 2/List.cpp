/*********************************************************************
** Program name:Shopping List
** Author: Ethan Dunham
** Date: 2/04/17
** Description: This is the implementation file for the List class.
*********************************************************************/
#include "List.hpp"
#include <string>
#include<iostream>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;


//This function overloads the == operator to compare names of 2 objects.
bool operator==(Item a, Item b);

//This is the default constructor for List
List::List()
{
	listArray = new Item*[4];
	oldListArray = new Item*[4];
	for (int i = 0; i < currentArraySize; i++)
	{
		listArray[i] = NULL;
		oldListArray[i] = NULL;
	}
}


//adds item to the list by adding to the array of Item objects.
void List::addToList(string itemName, string itemType, int quantity, double price)
{
	bool add=true;
	for (int i = 0; i < currentItems; i++)
	{
		Item search(itemName, itemType, quantity, price);
		if ((*(listArray[i]) == search))
		{
			add = false;
		}
	}

	if (add)
	{
		currentItems++;
		if (currentItems > currentArraySize)
		{
			for (int i = 0; i < currentArraySize; i++)
			{
				listArray[i] = NULL;
			}
			delete[] listArray;
			listArray = new Item *[currentItems];
			for (int i = 0; i < currentArraySize; i++)
			{
				listArray[i] = oldListArray[i];
			}

			listArray[currentArraySize] = new Item(itemName, itemType, quantity, price);

			for (int i = 0; i < currentArraySize; i++)
			{
				oldListArray[i] = NULL;
			}
			delete[] oldListArray;
			oldListArray = new Item *[currentItems];
			for (int i = 0; i < currentItems; i++)
			{
				oldListArray[i] = listArray[i];
			}
			currentArraySize++;
		}
		else
		{
			listArray[currentItems - 1] = new Item(itemName, itemType, quantity, price);
			oldListArray[currentItems - 1] = new Item(itemName, itemType, quantity, price);

		}
	}
	else
	{
		cout << "That item is alread in the list." << endl;
	}
}

//deletes from the list by creating a new array without the item to delete and deletes the item.
bool List::listDelete(string search, int quantityToDelete)
{
	bool deleted = false;
	for (int i = 0; i < currentItems; i++)//<= incase the item to delete is the last item on the list, decreasing current array size value
	{
		string itemName = (*listArray[i]).getItemName();
		if (itemName == search)
		{
			deleted = true;
			int quant = (*listArray[i]).getItemQuantity();
			if (quantityToDelete < quant)
			{
				(*listArray[i]).setItemQuantity(quant - quantityToDelete);
			}
			else
			{
				for (int i = 0; i < currentArraySize; i++)
				{
					listArray[i] = NULL;
				}
				delete[] listArray;
				if (currentItems > 5)
				{
					currentArraySize--;
					listArray = new Item *[currentArraySize];
					for (int i = 0; i < currentArraySize; i++)
					{
						listArray[i] = new Item();
					}
				}
				else
				{
					currentArraySize = 4;
					listArray = new Item *[4];
					for (int i = 0; i < 4; i++)
					{
						listArray[i] = new Item();
					}
				}
				int c = 0;
				int q = 0;
				while (q < currentItems)
				{
					if (q != i)
					{
						listArray[c] = oldListArray[q];
						q++;
						c++;
					}
					else
					{
						q++;
					}
				}
				if (currentItems > 5)
				{
					for (int i = 0; i < currentItems; i++)
					{
						oldListArray[i] = NULL;
					}

					delete[] oldListArray;
					oldListArray = new Item *[currentArraySize];
					for (int i = 0; i < currentArraySize; i++)
					{
						oldListArray[i] = new Item();
					}
				}
				else
				{
					if (currentItems == 5)
					{
						for (int i = 0; i < currentItems; i++)
						{
							oldListArray[i] = NULL;
						}
					}
					else
					{
						for (int i = 0; i < 4; i++)
						{
							oldListArray[i] = NULL;
						}
					}
					delete[] oldListArray;
					oldListArray = new Item *[4];
					for (int i = 0; i < 4; i++)
					{
						oldListArray[i] = new Item();
					}

				}
				currentItems--;
				for (int i = 0; i < currentItems; i++)
				{
					oldListArray[i] = listArray[i];
				}
			}
		}
	}

	return deleted;
}

//prints out the board for easy viewing.
void List::display()
{
	double total = 0;
	double itemTotal;
	cout << std::string(5, '\n');
	for (int i = 0; i < currentItems; i++)
	{
		itemTotal = (*listArray[i]).getItemPrice() * (*listArray[i]).getItemQuantity();
		cout << std::fixed << std::showpoint << std::setprecision(2);
		cout << "name: " << (*listArray[i]).getItemName() << "   Item Type: " << (*listArray[i]).getItemType()<< "   Quantity: "<< (*listArray[i]).getItemQuantity() << " Unit Price: $" << (*listArray[i]).getItemPrice() << " Total: $" << itemTotal << endl;
		total += itemTotal;
	}
	cout << std::fixed << std::showpoint << std::setprecision(2);
	cout << "                                                            Total Cost: $" << total << endl;
}

//deletes the lists
void List::exit()
{
	for (int i = 0; i < currentArraySize; i++)
	{
		delete listArray[i];
		delete oldListArray[i];
	}
	delete[] listArray;
	delete[] oldListArray;
}

//This function overloads the == operator to compare names of 2 objects.
bool operator==(Item a, Item b)
{
	bool Dup = false;
	string compare = a.getItemName();
	string tocomp = b.getItemName();
	if (compare == tocomp)
	{
		Dup = true;
	}
	return Dup;
}