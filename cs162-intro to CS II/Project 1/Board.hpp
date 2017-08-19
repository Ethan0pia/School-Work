/*********************************************************************
** Program name:The Ants Go Marching
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the header file for the board class
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:
	char **currentBoard;
	char **oldBoard;
	int height;
	int width;

public:
	Board(int, int);
	void writeAnt(int, int);
	char validMove(int, int);
	char getColor(int, int);
	void writeOldBoard();
	void changeColor(int, int);
	int getHeight();
	int getWidth();
	void print();
};
#endif