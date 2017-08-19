/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the implementation file for the Teacher class.
*********************************************************************/
#include"Teacher.hpp"
#include<iostream>
#include<string>
#include <iomanip>

//constructor
Teacher::Teacher(std::string name, int age, double tRating)
{
	this->personName = name;
	this->personAge = age;
	teacherRating = tRating;
}

//displays the info of the teacher.
void Teacher::DisplayInfo()
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout <<"Teacher's Name:" << personName << "     Teacher's Age:" << personAge << "     Teacher's Rating:" << teacherRating << std::endl;
}

//displays the amount of work done by the teacher.
void Teacher::Do_Work(int hours)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Instructor " << personName << " graded papers for " << hours << " hours." << std::endl;
}