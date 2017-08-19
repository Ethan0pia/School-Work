/******************************************************************
**Author: Ethan Dunham
**Date: 10/27/16
**Description: This is the header file for the LineSegment class.
*******************************************************************/
#include "Point.hpp"
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

class LineSegment {
private:
	Point end1;
	Point end2;

public:
	LineSegment(Point, Point);
	void setEnd1(Point);
	Point getEnd1();
	void setEnd2(Point);
	Point getEnd2();
	double length();
	double slope();
};
#endif