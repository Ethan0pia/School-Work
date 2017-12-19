/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the header for the Student class.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Person.hpp"

class Student :public Person
{
private:
	double studentGPA;

public:
	//constructor
	Student(std::string, int, double);
	//displays the info of the student.
	void DisplayInfo();
	//displays the amount worked.
	void Do_Work(int);
};

#endif
