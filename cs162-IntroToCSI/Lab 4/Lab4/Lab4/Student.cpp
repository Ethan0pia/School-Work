/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the implementation file for the Student class.
*********************************************************************/

#include"Student.hpp"
#include<iostream>
#include <iomanip>

//student constructor
Student::Student(std::string name, int age, double studGPA)
{
	this->personName = name;
	this->personAge = age;
	studentGPA = studGPA;
}

//prints the info for students
void Student::DisplayInfo()
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Student's Name:" << personName << "     Student's Age:" << personAge << "     Student's GPA:" << studentGPA << std::endl;
}

//prints the amount of work the student did.
void Student::Do_Work(int hours)
{
	std::cout << personName << " did " << hours << " hours of homework." << std::endl;
}