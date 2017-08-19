/*********************************************************************
** Program name:The Ants Go Marching
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the implementation file for Board class.
*********************************************************************/

#include "Board.hpp"
#include<iostream>
//#include <unistd.h>//sleep

using std::cout;
using std::cin;
using std::endl;

Board::Board(int size1, int size2)//constructor of blank board.
{
	height = size1;
	width = size2;

	currentBoard = new char*[height]; //dynamic array

	for (int i = 0; i < height; ++i) 
	{
		currentBoard[i] = new char[width];
	}
	
	oldBoard = new char*[height]; //dynamic array

	for (int i = 0; i < height; ++i)
	{
		oldBoard[i] = new char[width];
	}

}

void Board::writeAnt(int x, int y)
{

	currentBoard[x][y] = '*';
}

char Board::validMove(int x, int y)
{
	char valid = 'y';
	if (x<0 || y<0 || x>height || y>width)//off grid
	{
		valid = 'F';
	}
	return valid;
}

char Board::getColor(int X, int Y)
{
	char color = oldBoard[X][Y];
	return color;
}

void Board::writeOldBoard()
{
	for (int count1 = 0; count1 < width; count1++)
	{
		for (int count2 = 0; count2 < height; count2++)
		{
			oldBoard[count1][count2] = currentBoard[count1][count2];
		}
	}
}

void Board::changeColor(int x, int y)
{
	if (oldBoard[x][y] == '#')
	{
		currentBoard[x][y] = ' ';
	}
	else
	{
		currentBoard[x][y] = '#';
	}
}

int Board::getHeight()
{
	return height;
}

int Board::getWidth()
{
	return width;
}

void Board::print()
{
	//sleep(1);
	for (int count1 = 0; count1 < width; count1++)
	{
		for (int count2 = 0; count2 < height; count2++)
		{
			cout << currentBoard[count1][count2];
		}
		cout << endl;
	}
}