/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the implementation file for the University class.
*********************************************************************/
#include "University.hpp"
#include"Person.hpp"
#include "Teacher.hpp"
#include"Student.hpp"
#include"Building.hpp"
#include<iostream>
#include<vector>
using std::cout;
using std::endl;

//university constructor
University::University(string name)
{
	universityName = name;

}
//adds teacher to the vector if name is not already in data base.
void University::AddTeacher(string name, int age, double taRating)
{
	bool found = false;
	for (int i = 0; i < numOfPeople; i++)
	{
		if (((*people[i]).GetName()) == name)
		{
			found = true;
			cout << "That name is already in use. Please try again." << endl;
		}
	}
	if (!found)
	{
		people.emplace_back(new Teacher(name, age, taRating));
		numOfPeople++;

	}
}

//adds student to the vector if name is not already in data base.
void University::AddStudent(string name, int age, double gPa)
{
	bool found = false;
	for (int i = 0; i < numOfPeople; i++)
	{
		if (((*people[i]).GetName()) == name)
		{
			found = true;
			cout << "That name is already in use. Please try again." << endl;
		}
	}
	if (!found)
	{
		people.emplace_back(new Student(name, age, gPa));
		numOfPeople++;

	}
}

//adds building to the vector if name is not already in data base.
void University::AddBuilding(string name, string address, int squareFT)
{
	bool found = false;
	for (int i = 0; i < numOfBuildings; i++)
	{
		if (((*buildings[i]).GetName()) == name)
		{
			found = true;
			cout << "That name is already in use. Please try again." << endl;
		}
	}
	if (!found)
	{
		buildings.push_back(new Building(name, address, squareFT));
		numOfBuildings++;
	}
}

//calls the corresponding get work function
void University::Do_Work(int choice, int hours)
{
	(*people[choice]).Do_Work(hours);
}

//prints the buildings with numbers
void University::DisplayBuildings()
{
	cout << universityName << " buildings:" << endl;
	for (int i = 0; i < numOfBuildings; i++)
	{
		cout << i + 1 << ":";
		buildings[i]->DisplayInfo();
	}
}

//prints the people with numbers
void University::DisplayPeople()
{
	cout << universityName << " people:" << endl;
	for (int i = 0; i < numOfPeople; i++)
	{
		cout << i + 1 << ":";
		people[i]->DisplayInfo();
	}
}

//returns the number of people for verification in main of the menu.
int University::GetNumOfPeople()
{
	return numOfPeople;
}

//deletes the created objects to free memory.
void University::Exit()
{
	for (int i = 0; i < numOfBuildings; i++)
	{
		delete buildings[i];
	}
}