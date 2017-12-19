/*********************************************************************
** Program name:Determinant Calculator
** Author: Ethan Dunham
** Date: 1/15/17
** Description: Implementation file for the readMatrix function.
**				This function takes user input to fill a matrix.
*********************************************************************/

#include "readMatrix.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void readMatrix(int *matrix, int sizeOfMatrix)
{

	int num;
		
	cout << "Please enter " << sizeOfMatrix << " integers to populate the square matrix." << endl;

	for (int count = 0; count < sizeOfMatrix; count++)
	{
		cin >> num;
		*((matrix)+count) = num;
	}
}