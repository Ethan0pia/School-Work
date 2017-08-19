/*********************************************************************
** Author: Ethan Dunham
** Date: 10/10/16
** Description: This program will take integer input from a text file,
**				find their sum, and export a sum text file.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream inputFile;
	ofstream outputFile;
	string fileWithInt, sum = "sum.txt";//name of output file is predefined
	int total = 0, number;//starting total is 0

	cout << "What is the name of the file that contains integers?\n"
		"Please include \".txt\" and the file location if needed." << endl;
	cin >> fileWithInt;//the name of the input file

	inputFile.open(fileWithInt.c_str());//opens the input file

	if (inputFile) //validates that input file can be opened
	{
		while (inputFile >> number) //loops until no more int is found
			total += number;//adds the new into to the current total
	}
	else//outputs "could not access file" if the file cannot be found or opened
		cout << "Could not access file." << endl;

	inputFile.close();//closes input file as it is not needed anymore
	outputFile.open(sum);//opens or creates a file named "sum.txt"
	outputFile << total;//writes the total to the file
	outputFile.close();//closes the output file as it is not needed anymore

	return 0;
}