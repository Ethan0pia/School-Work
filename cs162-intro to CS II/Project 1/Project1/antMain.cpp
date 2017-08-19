/*********************************************************************
** Program name:The Ants Go Marching
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the main implementation file for the program
**				It creates a Langton's Ant.
*********************************************************************/
#include<iostream>
#include "Ant.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::srand;

int main()
{
	srand(time(NULL));// random time seed
	char facing='u';
	int startX=0, startY=0, turns=0, rows=0, columns=0;// initialize to 0 for random calculations later if needed

	menu(rows, columns, startX, startY, turns);

	if (rows == 0)//picks random if user didn't chose a value or if user picked 0.
	{
		rows = rand() % 50;
		while (startY > rows - 1)//if user picked start location, but not size. start location must be lower than size.
		{
			rows = rows + 5;
		}
	}

	if (columns == 0)
	{
		columns = rand() % 80;
		while (startX > rows - 1)
		{
			columns = columns + 5;
		}
	}

	if (startX==0)
	{
		startX = rand() % columns;
		while (startX > columns || startX<0)
		{
			startX = rand() % columns;
		}
		if (startX > 0)
		{
			startX--;
		}
	}

	if (startY==0)
	{
		startY = rand() % rows;
		while (startY > rows || startY<0)
		{
			startY = rand() % rows;
		}
		if (startY > 0)
		{
			startY--;
		}
	}

	if (turns == 0)
	{
		turns = rand() % 100+1;
	}

	Ant ant(facing, turns, startX, startY, rows, columns);//constructor
	ant.moveAnt();//start
	return 0;
}

