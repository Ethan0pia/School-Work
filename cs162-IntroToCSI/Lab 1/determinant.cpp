/**********************************************************************
** Program name:Determinant Calculator
** Author: Ethan Dunham
** Date: 1/15/17
** Description: Implementation file for the determinant function.
**				This function calculates the determinant of the matrix.
***********************************************************************/

#include "determinant.hpp"

int determinant(int *matrix, int sizeOfMatrix)//can't allocate a [][] matrix, so had to set it to [][3] since 3 is the limit needed.
{
	int determ;
	if (sizeOfMatrix == 4)//2x2 matrix.
	{
		int a = *(matrix);
		int b = *((matrix)+1);
		int c = *((matrix)+2);
		int d = *((matrix)+3);
		determ = a*d - b*c;//formula as per mathisfun.com
	}

	if (sizeOfMatrix == 9)//3x3 matrix.
	{
		int a = *(matrix);
		int b = *((matrix)+1);
		int c = *((matrix)+2);
		int d = *((matrix)+3);
		int e = *((matrix)+4);
		int f = *((matrix)+5);
		int g = *((matrix)+6);
		int h = *((matrix)+7);
		int i = *((matrix)+8);
		determ = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);//formula as per mathisfun.com
	}

	return determ;
}