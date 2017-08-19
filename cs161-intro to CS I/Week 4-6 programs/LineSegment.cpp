/******************************************************************
**Author: Ethan Dunham
**Date: 10/28/16
**Description: This is the functions for the LineSegment class.
*******************************************************************/

#include"Point.hpp"
#include<cmath>
#include"LineSegment.hpp"
#include<cmath>

/*********************************************************************
** Description: This constructor initializes the class.
**
*********************************************************************/
LineSegment::LineSegment(Point p1, Point p2)
{
	setEnd1(p1);
	setEnd2(p2);
}

/**********************************************************************
** Description: This function sets the end1 variable value.
**
*********************************************************************/
void LineSegment::setEnd1(Point p1)
{
	end1= p1;
}

/**********************************************************************
** Description: This function sends the end1 value when called.
**
*********************************************************************/
Point LineSegment::getEnd1()
{
	return end1;
}

/*********************************************************************
** Description: This function sets the end2 variable value.
**
*********************************************************************/
void LineSegment::setEnd2(Point p2)
{
	end2 = p2;
}

/*********************************************************************
** Description: This function sends the end1 value when called.
**
*********************************************************************/
Point LineSegment::getEnd2()
{
	return end2;
}

/*********************************************************************
** Description: This functions calculates the length of a line seg.
**
*********************************************************************/
double LineSegment::length()
{
	double length = end1.distanceTo(end2);
	return length;
}

/*********************************************************************
** Description: This function calculates the slope of the line seg.
**
*********************************************************************/
double LineSegment::slope()
{
	double slope;
	slope = (end2.getYCoord() - end1.getYCoord()) / (end2.getXCoord() - end1.getXCoord());
	return slope;
}