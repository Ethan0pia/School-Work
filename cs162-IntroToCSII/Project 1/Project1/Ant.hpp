/*********************************************************************
** Program name:The Ants Go Marching
** Author: Ethan Dunham
** Date: 1/22/17
** Description: This is the header file for the ant class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include<iostream>

class Ant
{
private:
	char facing;
	int turns;
	int plays;
	int currentY;
	int currentX;

	char **currentBoard;
	char **oldBoard;
	int rows;
	int columns;

	void moveBlack();
	void moveWhite();
	void changeColor();
	void print();


public:
	Ant(char, int , int, int, int, int);
	void moveAnt();

};

#endif