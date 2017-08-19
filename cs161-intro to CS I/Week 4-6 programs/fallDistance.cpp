/*********************************************************************
** Author: Ethan Dunham
** Date: 10/17/16
** Description: This function will find the distance that an object
**				falls in a given amount of time.
*********************************************************************/

#include <iostream>
#include <cmath>
/*
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
*/

double fallDistance(double time) {
	double d;//distance
	const double g = 9.8, half = 0.5;//gravity

	d = half*g*pow(time, 2.0);//distance formula

	return d;
}
//test main
/*
int main() {
	double time;
	double distance;
	cin >> time;
	distance = fallDistance(time);
	cout << fixed;
	cout << "Distance fallen is: " << distance << endl;
	return 0;
}
*/