/*********************************************************************
** Program name:Shopping List
** Author: Ethan Dunham
** Date: 2/04/17
** Description: This is the main file for the shopping List.
*********************************************************************/
#include<string>
#include<iostream>
#include "List.hpp"
#include "Item.hpp"
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void menu(List&);
bool cinFail();

int main()
{
	List *myList = new List();
	menu(*myList);
	delete myList;
	return 0;
}

//this menu is where most of the program is run. You pick the options and it runs the list.
void menu(List &myList)
{
	int exit = 0;
	while (exit == 0)//loops while user has not picked exit
	{
		char itemName[50];
		char itemType[50];
		double price = 0;
		int quantity = 0;
		int cont;
		char nameToDelete[50];
		int numToDelete;
		int option;
		bool deleted=true;

		do {//all do loops are validation of cin.fail()
			cout << "Option 1: Add item to list." << endl;
			cout << "Option 2: Remove item from list."<< endl;
			cout << "Option 3: Display the list." << endl;
			cout << "Option 4: Exit." << endl;
			cin >> option;
		} while (cinFail());

		switch (option)
		{
		case 1://add item
			do {//all do loops are validation of cin.fail()
				cout << std::string(5, '\n');
				do
				{
					cout << "What is the Item name?" << endl;
					std::cin.clear();
					std::cin.ignore(300, '\n');
					cin.getline(itemName, 50);
				} while (cinFail());

				do {
					cout << std::string(5, '\n');
					cout << "What does the item come in? Ex. 12oz bags, cans, box, etc." << endl;
					cin.getline(itemType, 50);
				} while (cinFail());

				do {
					cout << std::string(5, '\n');
					cout << "Enter the quantity you want to add." << endl;
					cin >> quantity;
				} while (cinFail() || quantity < 1);

				do {
					cout << std::string(5, '\n');
					cout << "Enter cost of each unit." << endl;
					cin >> price;
				} while (cinFail() || price < 0.01);

				do {
					cout << std::string(5, '\n');
					cout << "Is this correct?" << endl;
					cout << "Name: " << itemName << endl;
					cout << "Type: " << itemType << endl;
					cout << "Quantity: " << quantity << endl;
					cout << std::fixed << std::showpoint << std::setprecision(2);
					cout << "Price per unit: $" << price << endl;
					cout << "Enter 2 to start over with adding this item." << endl;
					cout << "Enter 1 to add this item and return to the main menu." << endl;
					cout << "Enter 0 to return to the main menu without adding this item." << endl;
					cin >> cont;
				} while (cinFail() || (cont != 1 && cont != 0 && cont != 2));
			} while (cont == 2);
			if (cont == 1)
			{
				myList.addToList(itemName, itemType, quantity, price);
			}
			cout << std::string(5, '\n');
			break;

		case 2://delete item
				do {
					do {
						cout << std::string(5, '\n');
						myList.display();
						cout << "What is the name of the item you wish to delete from the list?" << endl;
						cout << "This is case sensitive." << endl;
						std::cin.clear();
						std::cin.ignore(300, '\n');
						cin.getline(nameToDelete, 50);
					} while (cinFail());
					do
					{
						cout << std::string(5, '\n');
						cout << "How many of the item do you wish to remove from the list?" << endl;
						cin >> numToDelete;
					} while (cinFail() || numToDelete < 0);
					do {
						cout << std::string(5, '\n');
						cout << "Are you sure that you want to delete " << numToDelete << " " << nameToDelete << "?" << endl;
						cout << "Enter 2 to start over with deleting this item." << endl;
						cout << "Enter 1 to delete this item and return to the main menu." << endl;
						cout << "Enter 0 to return to the main menu without deleting this item." << endl;
						cin >> cont;
					} while (cinFail() || (cont != 1 && cont != 0 && cont != 2));
				} while (cont == 2);
				cout << std::string(5, '\n');
				if (cont == 1)
				{
					deleted = myList.listDelete(nameToDelete, numToDelete);
				}
				if (deleted)
				{
					cout << "The item was deleted successfully." << endl;
				}
				if (!deleted)
				{
					cout << "Item was not deleted successfully. Please try again." << endl;
				}
			break;

		case 3://display list
			myList.display();
			break;

		case 4://exit
			exit++;
		}
	}
	myList.exit();
	
	cout << "Thank you for using the best shopping list program ever made." << endl;
}

//Stops endless loops from user entering incorrect information that breaks the program.
bool cinFail()
{
	bool state;//validates cin statements
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(300, '\n');
		state = true;
	}
	else
	{
		state = false;
	}
	return state;
}