/************************************************************************
****Author: Ethan Dunham
****Date: 04/06/17
****Assignment: 0
****Description: This program generates a random number, converts it from
****			inchest to centimeters, then converts it from centimeters 
****			to inches.
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(0);
	char CR = '\n';
	int number = rand();
	double cm;
	double in;
	printf("The number to be converted is %d", number, "inches.");
	putchar(CR);
	cm = number * 2.54;
	printf("In centimeters, that is: %lf", cm);
	putchar(CR);
	in = cm / 2.54;
	printf("In inches, that is: %lf", in);
	putchar(CR);

	return 0;
}