/*********************************************************************
** Author: Ethan Dunham
** Date: 10/21/16
** Description: These functions are part of the box class
**				and will find the volume, surface area, and set width,
**				length, and height.
*********************************************************************/
#include "Box.hpp"

Box::Box() {
	height = width = length = 1;
}

Box::Box(double h, double w, double l) {
	height=h;
	width=w;
	length=l;
}

void Box::setHeight(double h) {
	if (h >= 0.0)
		height = h;
}

void Box::setWidth(double w) {
	if (w >= 0.0)
		width = w;
}

void Box::setLength(double l) {
	if (l >= 0.0)
		length = l;
}

double Box::getVolume() {
	double volume;
	volume = height*width*length;
	return volume;
}

double Box::getSurfaceArea() {
	double surfaceArea;
	surfaceArea = 2 * (height*width) + 2 * (height*length) + 2 * (width*length);
	return surfaceArea;
}