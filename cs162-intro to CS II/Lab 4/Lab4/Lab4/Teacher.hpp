/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the header for the Teacher class.
*********************************************************************/

#ifndef TEACHER_HPP
#define TEACHER_HPP
#include "Person.hpp"

class Teacher : public Person
{
private:
	double teacherRating;

public:
	//constructor
	Teacher(std::string, int, double);
	//displays the info of the teacher.
	void DisplayInfo();
	//prints the work done.
	void Do_Work(int);
};


#endif