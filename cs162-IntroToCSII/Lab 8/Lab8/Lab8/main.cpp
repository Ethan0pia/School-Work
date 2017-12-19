/**********************************************************************
** Program name:Read and Sort
** Author: Ethan Dunham
** Date: 3/3/17
** Description: This program demonstrates the understanding of sorting.
**********************************************************************/

#include<iostream>
#include<string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int linear(const int[], int, int);
void bubbleSort(int*, int );
int binary(const int [], int , int );
bool cinFail();
void case1();
void case2();
void case3();

int main()
{
	int option;
	string fileName;
	do {
		do {
			cout << "Option 1: Search the files for an integer." << endl;
			cout << "Option 2: Sort all files in ascending order." << endl;
			cout << "Option 3: Search for an integer using binary sort." << endl;
			cout << "Option 4: exit." << endl;
			cin >> option;
		} while (cinFail() || option < 0 || option > 4);
		switch (option)
		{
		case 1:
			case1();
			break;
		case 2:
			case2();
			break;

		case 3:
			case3();
			break;
		}


	} while (option != 4);
	return 0;
}

//linear search p596
int linear(const int list[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;
	while (index < size && !found)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

//binary search p599
int binary(const int array[], int size, int value)
{
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

//bubble sort, p607
void bubbleSort(int *array, int size)
{
	int temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

//Stops endless loops from user entering incorrect information that breaks the program.
bool cinFail()
{
	bool state;//validates cin statements
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(300, '\n');
		state = true;
	}
	else
	{
		state = false;
	}
	return state;
}


//search for int
void case1()
{
	int data[9];
	int data2[10];
	int data3[10];
	int data4[10];

	std::fstream file1;
	file1.open("original.txt");
	for (int i = 0; i < 9 ;i++)
	{
		file1 >> data[i];
	}

	std::fstream file2;
	file2.open("middle.txt");
	for (int i = 0; i < 10; i++)
	{
		file2 >> data2[i];
	}

	std::fstream file3;
	file3.open("beginning.txt");
	for (int i = 0; i < 10; i++)
	{
		file3 >> data3[i];
	}

	std::fstream file4;
	file4.open("end.txt");
	for (int i = 0; i < 10; i++)
	{
		file4 >> data4[i];
	}

	file1.close();
	file2.close();
	file3.close();
	file4.close();

	int value;
	int location;
	do {
		cout << "What integer would you like to search the files for?" << endl;
		cin >> value;
	} while (cinFail());
	location = linear(data, 9, value);
	if (location == -1)
	{
		cout << "That integer is not within the original.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the original.txt file." << endl;
	}

	location = linear(data2, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the middle.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the middle.txt file." << endl;
	}
	location = linear(data3, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the beginning.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the beginning.txt file." << endl;
	}
	location = linear(data4, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the end.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the end.txt file." << endl;
	}
	cout << endl;
}

//sorts
void case2()
{
	int data[9];
	int data2[10];
	int data3[10];
	int data4[10];

	std::fstream file1;
	file1.open("original.txt");
	for (int i = 0; i < 9; i++)
	{
		file1 >> data[i];
	}

	std::fstream file2;
	file2.open("middle.txt");
	for (int i = 0; i < 10; i++)
	{
		file2 >> data2[i];
	}

	std::fstream file3;
	file3.open("beginning.txt");
	for (int i = 0; i < 10; i++)
	{
		file3 >> data3[i];
	}

	std::fstream file4;
	file4.open("end.txt");
	for (int i = 0; i < 10; i++)
	{
		file4 >> data4[i];
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();

	char nameOfFile[100];
	do {
		cout << "What would you like the sorted original.txt file to be called?" << endl;
		std::cin.clear();
		std::cin.ignore(200, '\n');
		cin.getline(nameOfFile, 100);
	} while (cinFail());
	cout << "The original.txt file contained the values:" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	bubbleSort(data, 9);

	std::ofstream sorted1;
	sorted1.open(nameOfFile);
	cout << "The sorted file contains the values :" << endl;
	for (int i = 0; i < 9; i++)
	{
		sorted1 << data[i] << " ";
		cout << data[i] << " ";
	}
	sorted1.close();
	cout << endl;

	do {
		cout << "What would you like the sorted middle.txt file to be called?" << endl;
		std::cin.clear();
		cin.getline(nameOfFile, 100);
	} while (cinFail());
	cout << "The middle.txt file contained the values:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data2[i] << " ";
	}
	cout << endl;
	bubbleSort(data2, 10);

	std::ofstream sorted2;
	sorted2.open(nameOfFile);
	cout << "The sorted file contains the values :" << endl;
	for (int i = 0; i < 10; i++)
	{
		sorted2 << data2[i] << " ";
		cout << data2[i] << " ";
	}
	sorted2.close();
	cout << endl;

	do {
		cout << "What would you like the sorted beginning.txt file to be called?" << endl;
		std::cin.clear();
		cin.getline(nameOfFile, 100);
	} while (cinFail());
	cout << "The beginning.txt file contained the values:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data3[i] << " ";
	}
	cout << endl;

	bubbleSort(data, 10);

	std::ofstream sorted3;
	sorted3.open(nameOfFile);
	cout << "The sorted file contains the values :" << endl;
	for (int i = 0; i < 10; i++)
	{
		sorted3 << data3[i] << " ";
		cout << data3[i] << " ";
	}
	sorted3.close();
	cout << endl;

	do {
		cout << "What would you like the sorted end.txt file to be called?" << endl;
		std::cin.clear();
		cin.getline(nameOfFile, 100);
	} while (cinFail());
	cout << "The end.txt file contained the values:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data4[i] << " ";
	}
	cout << endl;
	bubbleSort(data4, 10);

	std::ofstream sorted4;
	sorted4.open(nameOfFile);
	cout << "The sorted file contains the values :" << endl;
	for (int i = 0; i < 10; i++)
	{
		sorted4 << data4[i] << " ";
		cout << data4[i] << " ";
	}
	sorted4.close();
	cout << endl;
}

//searches with binary
void case3()
{
	int data[9];
	int data2[10];
	int data3[10];
	int data4[10];

	std::fstream file1;
	file1.open("original.txt");
	for (int i = 0; i < 9; i++)
	{
		file1 >> data[i];
	}

	std::fstream file2;
	file2.open("middle.txt");
	for (int i = 0; i < 10; i++)
	{
		file2 >> data2[i];
	}

	std::fstream file3;
	file3.open("beginning.txt");
	for (int i = 0; i < 10; i++)
	{
		file3 >> data3[i];
	}

	std::fstream file4;
	file4.open("end.txt");
	for (int i = 0; i < 10; i++)
	{
		file4 >> data4[i];
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();

	string nameOfFile = "a.txt";
	bubbleSort(data, 9);

	std::ofstream sorted1;
	sorted1.open(nameOfFile);
	for (int i = 0; i < 9; i++)
	{
		sorted1 << data[i] << " ";
	}
	sorted1.close();

	nameOfFile = "b.txt";
	bubbleSort(data2, 10);

	std::ofstream sorted2;
	sorted2.open(nameOfFile);
	for (int i = 0; i < 10; i++)
	{
		sorted2 << data2[i] << " ";
	}
	sorted2.close();

	nameOfFile = "c.txt";
	bubbleSort(data, 10);

	std::ofstream sorted3;
	sorted3.open(nameOfFile);
	for (int i = 0; i < 10; i++)
	{
		sorted3 << data3[i] << " ";
	}
	sorted3.close();

	nameOfFile = "d.txt";
	bubbleSort(data4, 10);

	std::ofstream sorted4;
	sorted4.open(nameOfFile);
	for (int i = 0; i < 10; i++)
	{
		sorted4 << data4[i] << " ";
	}
	sorted4.close();
	cout << endl;

	int value;
	int location;
	do {
		cout << "What integer would you like to search the files for?" << endl;
		cin >> value;
	} while (cinFail());
	location = binary(data, 9, value);
	if (location == -1)
	{
		cout << "That integer is not within the original.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the original.txt file." << endl;
	}

	location = binary(data2, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the middle.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the middle.txt file." << endl;
	}
	location = binary(data3, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the beginning.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the beginning.txt file." << endl;
	}
	location = binary(data4, 10, value);
	if (location == -1)
	{
		cout << "That integer is not within the end.txt file." << endl;
	}
	else
	{
		cout << "That integer is at poition number " << location + 1 << "  of the end.txt file." << endl;
	}
	cout << endl;
}