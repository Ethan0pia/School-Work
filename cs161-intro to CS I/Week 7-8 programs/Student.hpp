/**********************************************************************
**Author: Ethan Dunham
**Date: 11/10/16
**Description: This is the header file for class Student
***********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
using std::string;

class Student 
{
private:
	string name;
	double score;

public:
	Student(string, double);
	string getName();
	double getScore();
};
#endif
