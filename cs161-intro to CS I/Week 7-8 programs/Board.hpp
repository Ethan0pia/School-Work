/*********************************************************************
** Author: Ethan Dunham
** Date: 11/16/16
** Description: This is the header file for the Board class.
***********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum state { X_WON, O_WON, DRAW, UNFINISHED };

class Board
{
private:
	char myBoard[3][3];//the board
	int plays;
	state currentState;

public:
	Board();//constructor of blank board.
	bool makeMove(int, int, char);//makes the inputted move.
	state gameState();//the current status of the game.
	void print();//prints the current board.

};
#endif