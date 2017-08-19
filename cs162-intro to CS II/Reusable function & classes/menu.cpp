/*****************************************************************************
** Program name: Menu
** Author: Ethan Dunham
** Date: 1/15/17
** Description: This is the implementation file for the reusable menu function
*******************************************************************************/

#include "menu.hpp"
#include "verification.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

const int maxSize = 500;

void menu(int &rows, int &columns, int &startX, int &startY, int &turns)
{
	int option;
	int run = 0;
	bool higher;
	bool lower;

		while (run == 0 || ((startX > columns - 1 && columns!=0) || (startY > rows - 1 && rows!=0)))//loops while values are invalid and run has not been chosen yet
		{
			run = 0;
			int option;
			cout << std::string(100, '\n');
			if (rows != 0 || columns != 0)
				if ((startX > columns - 1 && startX != 0 && columns !=0)|| (startY > rows - 1 && startY != 0 && rows != 0))//if user changes size after start location.
				{
					cout << "****Your ant is off the grid. Please fix your mistake.****" << endl;
				}
			do {//all do loops are validation of cin.fail()
				cout << "Option 1: Rows of the surface: " << rows << endl;
				cout << "Option 2: Columns of the surface: " << columns << endl;
				cout << "Option 3: Starting spot of ant: (" << startX << "," << startY << ")" << endl;
				cout << "Option 4: Number of turns: " << turns << endl;
				cout << "Option 5: Run program.*" << endl;
				cout << "*Values of 0 will be given random values when the program is run." << endl;
				cin >> option;
			} while (cinFail());

			switch (option)
			{
			case 1://rows
				do {
					cout << "How many rows should the board have? Recommended under 50." << endl;
					cin >> rows;
					higher = notLower0(rows);//validate that it is not less than 0
					lower = lessOrEqual(rows, maxSize);//validate that it is not higher than maxSize constant(500)

					while (!higher || !lower)
					{
						if (!higher)
						{
							cout << "Woah, there is nowhere for the ant to be, that is too small of a grid." << endl;
							cout << "How many rows should the board have? Under 500 and more than 0." << endl;
							cin >> rows;
						}

						if (!lower)
						{
							cout << "I don't think your screen resolution can handle that large of a grid, sorry." << endl;
							cout << "How many rows should the board have? Under 500 and more than 0." << endl;
							cin >> rows;
						}
						higher = notLower0(rows);
						lower = lessOrEqual(rows, maxSize);
					}
				} while (cinFail());
				break;

			case 2://columns
				do {
					cout << "How many columns should the board have? Recommended under 90." << endl;
					cin >> columns;

					higher = notLower0(columns);
					lower = lessOrEqual(columns, maxSize);

					while (!higher || !lower)//validation of board size.
					{
						if (!higher)
						{
							cout << "Woah, there is nowhere for the ant to be, that is too small of a grid." << endl;
							cout << "How many columns should the board have? Under 500 and more than 0." << endl;
							cin >> columns;
						}

						if (!lower)
						{
							cout << "I don't think your screen resolution can handle that large of a grid, sorry." << endl;
							cout << "How many columns should the board have? Under 500 and more than 0." << endl;
							cin >> columns;
						}
						higher = notLower0(columns);
						lower = lessOrEqual(columns, maxSize);
					}
				} while (cinFail());
				break;

			case 3://starting X and Y
				do {
					cout << "Where would you like the ant to start on the grid?" << endl;
					cout << "Please select two integers within the grid area of: (" << columns << "," << rows << ")" << endl;//for 2d matrixes, (x,y)=matrix[y][x]
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

							if (startX > maxSize || startY > maxSize)//for use when rows and columns are left at 0.
							{
								cout << endl;
								cout << "****That starting location is higher than the maximum number of rows and columns allowed.****" << endl;
								cout << "****Please keep the location between(500, 500)****" << endl << endl;
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

			case 4://turns
				do {
					if (turns < 0)//validation
					{
						cout << "Negative turns will not work. Please select a positive number or select 0 for random." << endl;
					}
					cout << "How many turns would you like the ant to take before stopping?" << endl;
					cin >> turns;
				} while (cinFail()||turns<0);
				break;
			case 5://run
				run++;
			}
		}
}