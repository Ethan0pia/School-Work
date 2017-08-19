/*****************************************************************************
** Author: Ethan Dunham
** Date:4/20/17
** Assignment: Program 2
** Description: This program creates a stack
******************************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post: returns 1 if even, 0 if not
*/
int isBalanced(char* s)
{
	DynArr *v;
	v = newDynArr(10);
	char next = nextChar(s);
	while (next != '\0')
	{
		if (next == '(' || next == '[' || next == '{')
		{
			pushDynArr(v, next);
		}
		else if(next == ')' || next == ']' || next == '}')
		{
			//if empty, it is not balanced
			if (isEmptyDynArr(v))
			{
				freeDynArr(v);
				return 0;
			}
			char i = topDynArr(v);
			if ((next == ')' && i !='(') && (next == '}' && i != '{') && (next == ']' && i != '['))
			{
				freeDynArr(v);
				return 0;
			}
			popDynArr(v);
		}
		next = nextChar(s);
	}

	if (!isEmptyDynArr(v))
	{
		freeDynArr(v);
		return 0;
	}
	freeDynArr(v);
	/* FIXME: You will write this function */		
	return 1;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

