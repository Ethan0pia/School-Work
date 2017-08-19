/******************************************************************
**Author: Ethan Dunham
**Date: 11/04/16
**Description: This function returns the mode of an aray.
*******************************************************************/

#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
typedef int arrayType[];

vector<int> findMode(arrayType nums, int size) 
{
	int numOfTimes = 0;
	int highestNum = 0;
	int numOfTimes2 = 0;
	bool add = true;//tells function to add number to mode vector.
	int modes = 0;
	vector<int> mode;//vector to be returned.

	//first loop finds highest number of times each number appears.
	for (int check = 0; check < size; check++)
	{
		//nested loop checks each number with the other numbers.
		for (int count = 0; count < size; count++)
		{
			//compares values, if the same, then adds to number frequency
			if (nums[check] == nums[count])
				numOfTimes++;
		}
		//compares the frequency of number checked to current highest number value
		if (numOfTimes > highestNum)
			highestNum = numOfTimes;

		numOfTimes = 0;//resets number back to 0 for next loop.
	}
	//second loop finds the numbers that are repeated highestNum times.
	for (int check = 0; check < size; check++)
	{

		for (int count = 0; count < size; count++)
		{
			if (nums[check] == nums[count])
				numOfTimes2++;
		}

		for (int loop = 0; numOfTimes2 == highestNum && loop < size && loop < modes; loop++)
		{
			if (mode[loop] == nums[check])
				add = false;
		}
		if (numOfTimes2 == highestNum)
		{
			if (add)
			{
				mode.push_back(nums[check]);
				modes++;
			}
		}
		add = true;
		numOfTimes2 = 0;
	}
		std::sort(mode.begin(), mode.end()); 
		return mode;
}

/*
using namespace std;
int main()
{
	vector<int> mode;
	int numbers[] = {12, 10, 12, 10, 5, 5, 3, 6, 9, 23};
	mode = findMode(numbers, 10);
	for (int count=0; count<5;count++)
		cout << mode[count] << endl;
	return 0;
}
*/
