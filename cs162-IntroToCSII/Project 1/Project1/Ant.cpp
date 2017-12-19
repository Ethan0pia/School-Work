/*********************************************************************
** Program name:The Ants Go Marching
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the implementation file for the Ant class.
*********************************************************************/

#include "Ant.hpp"
#include<iostream>
#include <string>
#include <unistd.h>//sleep

using std::cout;
using std::cin;
using std::endl;


Ant::Ant(char face, int numOfPlays, int xCoord, int yCoord, int height, int width)
{
	facing = face;
	turns = numOfPlays;
	currentX = xCoord;
	currentY = yCoord;
	plays = 0;
	rows = height;
	columns = width;

		currentBoard = new char*[rows]; //dynamic array

		for (int i = 0; i < rows; ++i)//writes array
		{
			currentBoard[i] = new char[columns];
		}

		oldBoard = new char*[rows]; //dynamic array

		for (int i = 0; i < rows; ++i)
		{
			oldBoard[i] = new char[columns];
		}

		for (int i = 0; i < rows; i++)//fills arrays
		{
			for (int r = 0; r < columns; r++)
			{
				currentBoard[i][r] = '-';
				oldBoard[i][r] = '-';
			}
		}
		currentBoard[currentY][currentX] = '^';//ant starts facing up
}

void Ant::changeColor()
{
	if (oldBoard[currentY][currentX] == ' ')
	{
		currentBoard[currentY][currentX] = '-';
	}
	else
	{
		currentBoard[currentY][currentX] = ' ';
	}
}

void Ant::print()
{
	sleep(1);//sleeps 1 second between turns
	cout << std::string(100, '\n');//makes display show black screen except what is needed.
	cout << "The Ants Are Marching" << endl;
	for (int count1 = 0; count1 < rows; count1++)
	{
		for (int count2 = 0; count2 < columns; count2++)
		{
			cout << currentBoard[count1][count2]<< " ";
		}
		cout << endl;
	}
}

void Ant::moveAnt()
{

	while (turns != plays)
	{
		char boardColor = oldBoard[currentY][currentX];
		print();

		if (boardColor == ' ')
		{
			moveBlack();
			plays++;
		}
		else//must be white space
		{
			moveWhite();
			plays++;
		}
	}
	cout << "The number of turns has been reached." << endl;

	for (int i = 0; i < rows; i++)//deletes the arrays to free memory
	{
		delete[] currentBoard[i];
		delete[] oldBoard[i];
	}
	delete[] currentBoard;
	delete[] oldBoard;
}

void Ant::moveWhite()
{
	switch(facing)
	{
	case 'u':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentX++;
		if (currentX == columns)//wraps the ant
		{
			currentX = 0;
		}
		currentBoard[currentY][currentX] = '>';//ant char changes based on direction it faces.
		facing = 'r';
		break;

	case 'd':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentX--;
		if (currentX < 0)
		{
			currentX = columns - 1;
		}
		currentBoard[currentY][currentX] = '<';
		facing = 'l';
		break;

	case 'l':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentY--;
		if (currentY < 0)
		{
			currentY = rows - 1;
		}
		currentBoard[currentY][currentX] = '^';
		facing = 'u';
		break;

	case 'r':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentY++;
		if (currentY == rows)
		{
			currentY = 0;
		}
		currentBoard[currentY][currentX] = 'v';
		facing = 'd';
	}
}

void Ant::moveBlack()
{
	switch(facing)
	{ 
	case 'u':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentX--;
		if (currentX < 0)
		{
			currentX = columns - 1;
		}
		currentBoard[currentY][currentX] = '<';
		facing = 'l';
		break;

	case 'd':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentX++;
		if (currentX == columns)
		{
			currentX = 0;
		}
		currentBoard[currentY][currentX] = '>';
		facing = 'r';
		break;

	case 'l':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentY++;
		if (currentY == rows)
		{
			currentY = 0;
		}
		currentBoard[currentY][currentX] = 'v';
		facing = 'd';
		break;
		

	case 'r':
		changeColor();
		oldBoard[currentY][currentX] = currentBoard[currentY][currentX];
		currentY--;
		if (currentY < 0)
		{
			currentY = rows - 1;
		}
		currentBoard[currentY][currentX] = '^';
		facing = 'u';
	}
}

