/**********************************************************************
** Program name:Palindrome and Queue
** Author: Ethan Dunham
** Date: 3/8/17
** Description: This call creates a character stack. Similar to p1078.
**********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP
#include<iostream>

class Stack
{
private:
	struct nodes
	{
		nodes *next;
		char character;
		nodes(char character1, nodes *next1 = NULL)
		{
			next = next1;
			character = character1;
		}
	};
	nodes *top;
public:
	//constructor
	Stack();
	//adds to top of stack
	void push(char);
	//removes top of stack
	void pop(char&);
};

#endif
