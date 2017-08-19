/******************************************************************
**Author: Ethan Dunham
**Date: 10/27/16
**Description: This is the header file for the point class.
*******************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

class Point 
{
private:
	double xCoord, yCoord;

public:
	Point(double, double);
	Point();
	void setXCoord(double);
	double getXCoord();
	void setYCoord(double);
	double getYCoord();
	double distanceTo(const Point &);
};
#endif