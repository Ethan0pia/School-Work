/* CS261- Assignment 1 - Q.2*/
/* Name: Ethan Dunham
* Date: 4/12/17
 * Solution description: This manipulates parameters passed by value vs reference.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    /*Set b to half its original value*/
	*b = *b / 2;
	/*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5, y = 6, z = 7;
    /*Print the values of x, y and z*/
	printf("X=%d\n",x);
	printf("Y=%d\n",y);
	printf("Z=%d\n",z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
	int c = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("C=%d\n", c);
    /*Print the values of x, y and z again*/
	printf("X=%d\n", x);
	printf("Y=%d\n", y);
	printf("Z=%d\n", z);
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
    
    
