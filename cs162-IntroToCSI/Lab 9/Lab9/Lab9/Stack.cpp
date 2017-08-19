/**********************************************************************
** Program name:Palindrome and Queue
** Author: Ethan Dunham
** Date: 3/8/17
** Description: This implemets the stack class. Similar to p1078.
**********************************************************************/

#include "Stack.hpp"

//constructor
Stack::Stack()
{
	top = NULL;
}

//adds to top of stack
void Stack::push(char character)
{
	top = new nodes(character, top);
}

//removes top of stack
void Stack::pop(char &character)
{
	character = top->character;
	nodes *temp = top;
	top = top->next;
	delete temp;
}