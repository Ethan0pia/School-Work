/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the header for the University class.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
#include "Building.hpp"
#include"Person.hpp"
#include"Teacher.hpp"
#include"Student.hpp"
#include<string>
#include<vector>
#include <memory>
using std::string;

class University
{
private:
	string universityName;
	std::vector<Building*> buildings;
	int numOfBuildings = 0;
	std::vector<std::unique_ptr<Person>> people;
	int numOfPeople = 0;
public:
	//constructor
	University(string);
	//adds a teacher to the vector of people.
	void AddTeacher(string, int, double);
	//adds a student to the vector of people
	void AddStudent(string, int, double);
	//adds a building to the vector of buildings
	void AddBuilding(string, string, int);
	//tells the person selected to do work.
	void Do_Work(int, int);
	//prints the buildings in the vector with numbers.
	void DisplayBuildings();
	//prints the people in the vector with numbers.
	void DisplayPeople();
	//returns the number of people for validation.
	int GetNumOfPeople();
	//deletes used memory.
	void Exit();
};


#endif