/* CS261- Assignment 1 - Q. 0*/
/* Name: Ethan Dunham
 * Date: 4/12/17
 * Solution description: This prints values and addresses of a pointer.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("%d\n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("%d\n", iptr);
     /*Print the address of iptr itself*/
	printf("%d\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 10;
    /*print the address of x*/
	printf("%d\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("%d\n", &x);
    return 0;
}
