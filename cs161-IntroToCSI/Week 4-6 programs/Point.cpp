/******************************************************************
**Author: Ethan Dunham
**Date: 10/27/16
**Description: This file contains the functions for Point.hpp.
*******************************************************************/

#include"Point.hpp"
#include<cmath>

/*********************************************************************
** Description: This function sets the default point at (0,0)
**
*********************************************************************/
Point::Point()
{
	setXCoord(0);
	setYCoord(0);
}

/*********************************************************************
** Description: This function is the constructor and initialized the
**				values of the object.
*********************************************************************/
Point::Point(double x, double y)
{
	setXCoord(x);
	setYCoord(y);
}

/*********************************************************************
** Description: This function sets the xCoord variable.
**
*********************************************************************/
void Point::setXCoord(double x)
{
	xCoord = x;
}

/*********************************************************************
** Description: This function sends the xCoord value when called.
**
*********************************************************************/
double Point::getXCoord()
{
	return xCoord;
}

/*********************************************************************
** Description: This function sets the yCoord variable.
**
*********************************************************************/
void Point::setYCoord(double y)
{
	yCoord = y;
}

/*********************************************************************
** Description: This function sends the xCoord value when called.
**
*********************************************************************/
double Point::getYCoord()
{
	return yCoord;
}

/*********************************************************************
** Description: This function calculates the distance between 2 points.
**
*********************************************************************/
double Point::distanceTo(const Point &p2 )
{
	double difX = p2.xCoord - xCoord;
	double difY = p2.yCoord - yCoord;
	double distance = sqrt(pow(difX, 2) + pow(difY, 2));
	return distance;
}