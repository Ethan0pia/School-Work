/**********************************************************************
**Author: Ethan Dunham
**Date: 11/10/16
**Description: This is the implementation file for student class
***********************************************************************/

#include <string>
using std::string;
#include "Student.hpp"

/**********************************************************************
**Description: This is the constructor for the Student class.
***********************************************************************/
Student::Student(string studentName, double grade)
{
	name = studentName;
	score = grade;
}

/**********************************************************************
**Description: This is the get function for the name.
***********************************************************************/
string Student::getName()
{
	return name;
}

/**********************************************************************
**Description: This is the get function for the score.
***********************************************************************/
double Student::getScore()
{
	return score;
}
