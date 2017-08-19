
/*********************************************************************
** Author: Ethan Dunham
** Date: 10/21/16
** Description: This header file is for the box class.
***********************************************************************/
#ifndef BOX_HPP
#define BOX_HPP
class Box 
{
	private:
		double height;
		double width;
		double length;

	public:
		Box();
		Box(double, double, double);
		void setHeight(double);
		void setWidth(double);
		void setLength(double);
		double getVolume();
		double getSurfaceArea();
};
#endif