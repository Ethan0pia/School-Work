#include<iostream>
#include "Box.hpp"
using namespace std;
int main() {
	Box box1(2.4, 7.1, 5.0);
	Box box2;
	double volume1 = box1.getVolume();
	cout << volume1<<endl;
	double surfaceArea1 = box1.getSurfaceArea();
	cout << surfaceArea1<<endl;
	double volume2 = box2.getVolume();
	cout << volume2<<endl;
	double surfaceArea2 = box2.getSurfaceArea();
	cout << surfaceArea2<<endl;
	return 0;
}