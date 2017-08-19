/**************************************************************************
** Author: Ethan Dunham
** Date: 11/16/16
** Description: This is the implementation file for the TicTacToe class.
***************************************************************************/

#include "TicTacToe.hpp"
#include<iostream>
#include "Board.hpp"

/**************************************************************************
** Description: This is the constructor for the TicTacToe class.
***************************************************************************/
TicTacToe::TicTacToe(char yORx)
{
	player = yORx;
	Board theBoard();
}

/**************************************************************************
** Description: This function plays tic tac toe between 2 players.
***************************************************************************/
void TicTacToe::play()
{
	state currentState = UNFINISHED;

	while (currentState == UNFINISHED)
	{
		int x, y;
		bool played;
		theBoard.print();

		std::cout << "It is player " << player << "'s turn.\n"
				"Please make a selection on the board." << std::endl;

		std::cin >> x;
		std::cin >> y;

		while (x > 2 || y > 2 || x < 0 || y < 0)//verify user input.
		{
			std::cout << "Please select two valid numbers between 0 and 2." << std::endl;
			std::cin >> x;
			std::cin >> y;
		}

		played = theBoard.makeMove(x, y, player);//makes move and verifies that it was made.

		while (!played)//checks to make sure played is true.
		{
			std::cout << "That spot is already taken.\n"
					"Please Make another selection." << std::endl;
			std::cin >> x;
			std::cin >> y;
			played = theBoard.makeMove(x, y, player);
		}
		if (player == 'x')
			player = 'o';
		else
			player = 'x';

		currentState = theBoard.gameState();

		switch (currentState)
		{
			case X_WON: theBoard.print(); 
				std::cout << "Player x won the game." << std::endl; 
				break;
			case O_WON: theBoard.print(); 
				std::cout << "Player o won the game." << std::endl; 
				break;
			case DRAW: theBoard.print(); 
				std::cout << "The game is a draw." << std::endl;
		}
	}
}


int main()
{
	char player;

	std::cout << "Should x or o go first?" << std::endl;//asks which player should go first.
	std::cin >> player;

	if (player == 'x' || player == 'X')//does the function of makelower
		player = 'x';

	else
		player = 'o';

	TicTacToe whoFirst(player);//sets first player
	whoFirst.play();//begins the game

	std::cout << "Thank you for playing." << std::endl;

	return 0;
}