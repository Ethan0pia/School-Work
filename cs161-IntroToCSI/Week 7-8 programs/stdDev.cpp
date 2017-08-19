/**********************************************************************
**Author: Ethan Dunham
**Date: 11/10/16
**Description: This is the implementation file for the function stdDev.
***********************************************************************/

#include <cmath>
#include "Student.hpp"

double stdDev(Student *students[], int size)
{
	double deviation;
	double total1 = 0;
	double mean;
	double squaredMean;

	//work out the mean.
	for (int count = 0; count < size; count++)
	{
		total1 += (*students[count]).getScore();
	}
	
	mean = total1 / size;
	
	double total2 = 0;
	//works
	//subtract the mean and square the results.
	for (int count = 0; count < size; count++)
	{
		double difference = (*students[count]).getScore() - mean;
		double square = pow(difference,2);
		total2 += square;
	}
	
	//find the mean of the squared differences.
	squaredMean = total2 / size;
	//square the the mean of the squared differences.
	deviation = sqrt(squaredMean);
	//return the deviation.
	return deviation;
}

/*
#include<iostream>
using namespace std;
int main() 
{
Student s1 = Student("a", 13), s2 = Student("b", 23), s3 = Student("c", 12);
Student *myArray[] = {&s1, &s2, &s3};
cout << stdDev(myArray, 3) << endl;
return 0;
}
*/