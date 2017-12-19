/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the header for the Person class.
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP
#include<iostream>
#include<string>

class Person
{
protected:
	std::string personName;
	int personAge;

public:
	//default function for displaying info to be over ridden with polymorphism.
	virtual void DisplayInfo() {};
	//default function for displaying work to be over ridden with polymorphism.
	virtual void Do_Work(int) {};
	//default function for returning the name of a person for validation.
	std::string GetName()
	{
		return personName;
	};
	//destructor to be overridden.
	virtual ~Person() {};
};

#endif