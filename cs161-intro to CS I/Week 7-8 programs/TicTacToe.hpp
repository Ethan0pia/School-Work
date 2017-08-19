/*********************************************************************
** Author: Ethan Dunham
** Date: 11/16/16
** Description: This is the header file for the TicTacToe class.
***********************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
private:
	char player;//keeps track of player
	Board theBoard;

public:
	TicTacToe(char);
	void play();

};
#endif