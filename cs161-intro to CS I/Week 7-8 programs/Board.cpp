/***************************************************************************************************************
** Author: Ethan Dunham
** Date: 11/16/16
** Description: This is the implementation file for the Board class.
*****************************************************************************************************************/

#include "Board.hpp"
#include<iostream>

/***************************************************************************************************************
** Description: This function is the constructor for the board and the initial value of plays.
*****************************************************************************************************************/
Board::Board()//constructor of blank board.
{
	//resets the board to all "."
	for (int count1 = 0; count1 < 3; count1++)
	{
		for (int count2 = 0; count2 < 3; count2++)
			myBoard[count1][count2] = '.';
	}
	plays = 0;
}

/***************************************************************************************************************
** Description: This function makes the move that the player specifies if possible, or returns false.
*****************************************************************************************************************/
bool Board::makeMove(int x, int y, char player)//makes the inputted move.
{
	bool played;
	if (myBoard[x][y] == '.')//if the board spot is a period, then it replaces the value with the player's char.
	{
		myBoard[x][y] = player;
		played = true;//set played to true so that it returns that it moved.
		plays++;//adds to plays, since a game can only be 9 plays long.
	}
	else
		played = false;
	return played;
}

/***************************************************************************************************************
** Description: This enum function checks to see if the game is done or needs to be continued.
*****************************************************************************************************************/
state Board::gameState()//the current status of the game.
{
	//The 8 possible ways to win. Adding their char value for later.
	int row1 = myBoard[0][0] + myBoard[0][1] + myBoard[0][2];
	int row2 = myBoard[1][0] + myBoard[1][1] + myBoard[1][2];
	int row3 = myBoard[2][0] + myBoard[2][1] + myBoard[2][2];
	int row4 = myBoard[0][0] + myBoard[1][0] + myBoard[2][0];
	int row5 = myBoard[0][1] + myBoard[1][1] + myBoard[2][1];
	int row6 = myBoard[0][2] + myBoard[1][2] + myBoard[2][2];
	int row7 = myBoard[0][0] + myBoard[1][1] + myBoard[2][2];
	int row8 = myBoard[0][2] + myBoard[1][1] + myBoard[2][0];

	//the value of 3*char x=360. Checks rows to see if there is an x winner.
	if (row1 == 360 || row2 == 360 || row3 == 360 || row4 == 360 || row5 == 360 || row6 == 360 || row7 == 360 || row8 == 360)
		currentState = X_WON;

	//the value of 3*char o=333. Checks rows to see if there is an o winner.
	else if (row1 == 333 || row2 == 333 || row3 == 333 || row4 == 333 || row5 == 333 || row6 == 333 || row7 == 333 || row8 == 333)
		currentState = O_WON;

	//if there have been 9 plays and no winner, the game is over with a draw.
	else if (plays == 9)
		currentState = DRAW;

	//Super long "smart" draw to check if there is a possible way to win 
	else if (plays > 6 && row1 -'.'+'x'!=360 && row2 - '.' + 'x' != 360 && row3 - '.' + 'x' != 360 && row4 - '.' + 'x' != 360 && 
			row5 - '.' + 'x' != 360 && row6 - '.' + 'x' != 360 && row7 - '.' + 'x' != 360 && row8 - '.' + 'x' != 360
			&& row1 - '.' +'o'!=333 && row2 - '.' + 'o' != 333&& row3 - '.' + 'o' != 333&& row4 - '.' + 'o' != 333
			&& row5 - '.' + 'o' != 333 && row6 - '.' + 'o' != 333 && row7 - '.' + 'o' != 333 && row8 - '.' + 'o' != 333)
		currentState = DRAW;
	//if none of the previous hold true, the game continues.
	else
		currentState = UNFINISHED;

	return currentState;
}

/***************************************************************************************************************
** Description: This function prints the current board.
*****************************************************************************************************************/
void Board::print()//prints the current board.
{
	std::cout << "  " << "0" << " " << "1" << " " << "2" << std::endl;
	std::cout << "0" << " " << myBoard[0][0] << " " << myBoard[0][1] << " " << myBoard[0][2] << std::endl;
	std::cout << "1" << " " << myBoard[1][0] << " " << myBoard[1][1] << " " << myBoard[1][2] << std::endl;
	std::cout << "2" << " " << myBoard[2][0] << " " << myBoard[2][1] << " " << myBoard[2][2] << std::endl;
}