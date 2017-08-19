/********************************************************************* 
** Program name: Determinant Calculator
** Author: Ethan Dunham
** Date: 1/15/17 
** Description: This program calculates the determinant of each part 
**				of a user entered 2x2 or 3x3 matrix.
*********************************************************************/

#include "determinant.hpp"
#include "readMatrix.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int repeat = 0;
	while (repeat == 0)
	{

		int size;
		cout << "Do you wish to make a 2x2 (enter \'2\') or 3x3 (enter \'3\') matrix?" << endl;
		cin >> size;

		if (size == 2)
		{
			int matrix[2][2];
			readMatrix(*matrix, 4);
			int total = determinant(*matrix,4);
			cout << endl << endl << endl << "This is your matrix:" << endl;
			cout << matrix[0][0] << " " << matrix[0][1] << endl;
			cout << matrix[1][0] << " " << matrix[1][1] << endl;
			cout << "The determinant is: " << total << endl;
			repeat = 1;
		}

		else if (size == 3)
		{
			int matrix[3][3];
			readMatrix(*matrix, 9);
			int total = determinant(*matrix, 9);
			cout << endl << endl << endl << "This is your matrix:" << endl;
			cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] <<endl;
			cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << endl;
			cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << endl;
			cout << "The determinant is: " << total << endl;
			repeat = 1;
		}
		else
		{
			cout << "Please pick a valid sized matrix." << endl;
		}
	}
	return 0;
}