/*****************************************************************************
** Program name: Menu
** Author: Ethan Dunham
** Date: 1/15/17
** Description: This is the implementation file for the reusable menu function
*******************************************************************************/

#include "Menu.hpp"
#include "verification.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

const int maxSize = 95;

void menu(int &rows, int &columns, int &startX, int &startY, int &turns)
{
	int option;
	int run = 0;
	bool higher;
	bool lower;

		while (run == 0 || ((startX > columns - 1 && columns!=0) || (startY > rows - 1 && rows!=0)))
		{
			run = 0;
			int option;
			cout << std::string(100, '\n');
			if (rows != 0 || columns != 0)
				if ((startX > columns - 1 && startX != 0 && columns !=0)|| (startY > rows - 1 && startY != 0 && rows != 0))
				{
					cout << "****Your ant is off the grid. Please fix your mistake.****" << endl;
				}
			do {
				cout << "Option 1: Rows of the surface: ";
				if (rows != 0)
				{
					cout << rows;
				}
				cout << endl;

				cout << "Option 2: Columns of the surface: ";
				if (columns != 0)
				{
					cout << columns;
				}
				cout << endl;

				cout << "Option 3: Starting spot of ant: ";
				if (startX != 0)
				{
					cout << "(" << startX << "," << startY << ")";
				}
				cout << endl;

				cout << "Option 4: Number of turns: ";
				if (turns != 0)
				{
					cout << turns;
				}
				cout << endl;

				cout << "Option 5: Run program.*" << endl;
				cout << "*Any option not changed will be given a random value. Values of 0 will be given random values." << endl;
				cin >> option;
			} while (cinFail());

			switch (option)
			{
			case 1:
				do {
					cout << "How many rows should the board have? Recommended around 50." << endl;
					cin >> rows;
					higher = notLower0(rows);
					lower = lessOrEqual(rows, maxSize);

					while (!higher || !lower)//validation of board size.
					{
						if (!higher)
						{
							cout << "Woah, there is nowhere for the ant to be, that is too small of a grid." << endl;
							cout << "How many rows should the board have? Under 95 and more than 0." << endl;
							cin >> rows;
						}

						if (!lower)
						{
							cout << "I don't think your screen resolution can handle that large of a grid, sorry." << endl;
							cout << "How many rows should the board have? Under 95 and more than 0." << endl;
							cin >> rows;
						}
						higher = notLower0(rows);
						lower = lessOrEqual(rows, maxSize);
					}
				} while (cinFail());
				break;

			case 2:
				do {
					cout << "How many columns should the board have? Recommended arround 50." << endl;
					cin >> columns;

					higher = notLower0(columns);
					lower = lessOrEqual(columns, maxSize);

					while (!higher || !lower)//validation of board size.
					{
						if (!higher)
						{
							cout << "Woah, there is nowhere for the ant to be, that is too small of a grid." << endl;
							cout << "How many columns should the board have? Under 95 and more than 0." << endl;
							cin >> columns;
						}

						if (!lower)
						{
							cout << "I don't think your screen resolution can handle that large of a grid, sorry." << endl;
							cout << "How many columns should the board have? Under 95 and more than 0." << endl;
							cin >> columns;
						}
						higher = notLower0(columns);
						lower = lessOrEqual(columns, maxSize);
					}
				} while (cinFail());
				break;

			case 3:
				do {
					cout << "Where would you like the ant to start on the grid?" << endl;
					cout << "Please select two integers within the grid area of: (" << columns << "," << rows << ")" << endl;
					if (columns == 0 || rows == 0)
							{
								cout << "Note: The 0 values displayed in (" << columns << "," << rows << ") will be given random values based on your" << endl;
								cout << "choice of starting location unless you fill in those options prior to running the program." << endl;
							}
					cout << "Enter 2 integers seperated by a space." << endl;
					cin >> startX >> startY;

						while ((startX > columns - 1 && columns !=0) || startX<0 || (startY>rows - 1 && rows !=0) || startY < 0 || startX>maxSize || startY>maxSize)
						{
							if (startX < 0 || startY < 0)
							{
								"****Your ant can't be at a location lower than 0. Please try again.****";
							}

							if (startX > maxSize || startY > maxSize)
							{
								cout << endl;
								cout << "****That starting location is higher than the maximum number of rows and columns allowed.****" << endl;
								cout << "****Please keep the location between(95, 95)****" << endl << endl;
							}

							cout << "The ant is in North Korea, or some other location off the grid. Please try again." << endl;
							cout << "Please select two integers within the grid area of: (" << columns << "," << rows << ")" << endl;
							if (columns == 0 || rows == 0)
							{
								cout << "Note: The 0 values displayed in (" << columns << "," << rows << ") will be given random values based on your" << endl;
								cout << "choice of starting location unless you fill in those options prior to running the program." << endl;
							}
							cout << "Enter 2 integers seperated by a space." << endl;
							cin >> startX >> startY;
						}

					startX--;
					startY--;
				} while (cinFail());
				break;

			case 4:
				do {
					cout << "How many turns would you like the ant to take before stopping?" << endl;
					cin >> turns;
				} while (cinFail());
				break;
			case 5:
				run++;
			}
		}
}