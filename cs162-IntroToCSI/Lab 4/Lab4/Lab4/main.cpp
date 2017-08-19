/*********************************************************************
** Program name:Uni Database
** Author: Ethan Dunham
** Date: 2/5/17
** Description: This is the main implementation file for the program.
*********************************************************************/

#include "University.hpp"
#include "Person.hpp"
#include"Building.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include<iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

//cin.fail function for validation and fixing
bool cinFail();

//main function to run the program, includes the menu.
int main()
{
	University oSu("Oregon State University");
	oSu.AddBuilding("Gilbert Hall", "2100 SW MONROE AVE CORVALLIS, OR 97331", 85700);
	oSu.AddBuilding("Fairbanks Hall", "220 SW 26TH STREET CORVALLIS, OR 97331", 37286);

	oSu.AddStudent("Jeff Williams", 19, 2.9);
	oSu.AddStudent("Betty White", 75, 3.8);
	oSu.AddTeacher("John Smith", 39, 4.5);
	oSu.AddTeacher("Ben Forman", 65, 3.2);

		char name[50] = {};
		char address[50] = {};
		double gPA = 0;
		double teachRating = 0;
		int exit=0;
		char nameToFind[50] = {};
		int age = 0;
		int option;
		int squareFT = 0;
		int hours = 0;
		int cont = 0;
		while (exit == 0)//loops while user has not picked exit
		{
			do {//all do loops are validation of cin.fail()
				cout << std::string(2, '\n');
				cout << "Option 1: Admit a new student to the university." << endl;
				cout << "Option 2: Hire a new teacher to the university." << endl;
				cout << "Option 3: Add a building university database." << endl;
				cout << "Option 4: Display the buildings of the university." << endl;
				cout << "Option 5: Display all the people at the university." << endl;
				cout << "Option 6: Have the person do some work." << endl;
				cout << "Option 7: Exit." << endl;
				cin >> option;
			} while (cinFail());

			switch (option)
			{
			case 1://add student
				do {//all do loops are validation of cin.fail()
					cout << std::string(5, '\n');
					do
					{
						cout << "What is the student's name?" << endl;
						std::cin.clear();
						std::cin.ignore(300, '\n');
						cin.getline(name, 50);
					} while (cinFail());

					do {
						cout << std::string(5, '\n');
						cout << "Enter the student's age." << endl;
						cin >> age;
						if (age < 10 || age>120)
						{
							cout << "That is too young or too old to be in college, please pick a valid age between 10 and 120." << endl;
						}
					} while (cinFail() || age < 10 || age > 120);

					do {
						cout << std::string(5, '\n');
						cout << "Enter the student's GPA." << endl;
						cin >> gPA;
						if (gPA < 0 || gPA>4)
						{
							cout << "A GPA must be between 0.0 and 4.0." << endl;
						}
					} while (cinFail() || gPA < 0 || gPA>4);
					do {
						cout << std::string(5, '\n');
						cout << "Is this correct?" << endl;
						cout << "Name: " << name << endl;
						cout << "Age: " << age << endl;
						std::cout << std::setprecision(1);
						cout << "GPA: " << gPA << endl;
						cout << "Enter 2 to start over with adding this student." << endl;
						cout << "Enter 1 to add this student and return to the main menu." << endl;
						cout << "Enter 0 to return to the main menu without adding this student." << endl;
						cin >> cont;
					} while (cinFail() || (cont != 1 && cont != 0 && cont != 2));
				} while (cont == 2);
				if (cont != 0)
				{
					oSu.AddStudent(name, age, gPA);
				}
				cout << std::string(5, '\n');
				break;

			case 2://add teacher
				do {//all do loops are validation of cin.fail()
					cout << std::string(5, '\n');
					do
					{
						cout << "What is the teacher's name?" << endl;
						std::cin.clear();
						std::cin.ignore(300, '\n');
						cin.getline(name, 50);
					} while (cinFail());

					do {
						cout << std::string(5, '\n');
						cout << "Enter the teacher's age." << endl;
						cin >> age;
						if (age < 20 || age>120)
						{
							cout << "That is too young or too old to be a teacher, please pick a valid age between 20 and 120." << endl;
						}
					} while (cinFail() || age < 20 || age > 120);

					do {
						cout << std::string(5, '\n');
						cout << "Enter the teacher's rating." << endl;
						cin >> teachRating;
						if (teachRating < 0 || teachRating>5)
						{
							cout << "A GPA must be between 0.0 and 5.0." << endl;
						}
					} while (cinFail() || teachRating < 0 || teachRating>5);
					do {
						cout << std::string(5, '\n');
						cout << "Is this correct?" << endl;
						cout << "Name: " << name << endl;
						cout << "Age: " << age << endl;
						std::cout << std::setprecision(1);
						cout << "Rating: " << teachRating << endl;
						cout << "Enter 2 to start over with adding this teacher." << endl;
						cout << "Enter 1 to add this teacher and return to the main menu." << endl;
						cout << "Enter 0 to return to the main menu without adding this teacher." << endl;
						cin >> cont;
					} while (cinFail() || (cont != 1 && cont != 0 && cont != 2));
				} while (cont == 2);
				if (cont != 0)
				{
					oSu.AddTeacher(name, age, teachRating);
				}
				cout << std::string(5, '\n');
				break;

			case 3://add a building
				do {//all do loops are validation of cin.fail()
					cout << std::string(5, '\n');
					do {
						cout << "What is the building's name?" << endl;
						std::cin.clear();
						std::cin.ignore(300, '\n');
						cin.getline(name, 50);
					} while (cinFail());

					do {
						cout << std::string(5, '\n');
						cout << "Enter the square footage of the building to the nearest foot." << endl;
						cin >> squareFT;
						if (squareFT < 1000 || squareFT > 400000)
						{
							cout << "That is too big or small to be a building on campus." << endl;
						}
					} while (cinFail() || squareFT < 1000 || squareFT > 400000);

					do {
						cout << std::string(5, '\n');
						cout << "Enter the building's address." << endl;
						cin.getline(address, 50);
					} while (cinFail());

					do {
						cout << std::string(5, '\n');
						cout << "Is this correct?" << endl;
						cout << "Name: " << name << endl;
						cout << "Address: " << address << endl;
						cout << "Square Footage: " << squareFT << endl;
						cout << "Enter 2 to start over with adding this building." << endl;
						cout << "Enter 1 to add this building and return to the main menu." << endl;
						cout << "Enter 0 to return to the main menu without adding this building." << endl;
						cin >> cont;
					} while (cinFail() || (cont != 1 && cont != 0 && cont != 2));
				} while (cont == 2);
				if (cont != 0)
				{
					oSu.AddBuilding(name, address, squareFT);
				}
				cout << std::string(5, '\n');
				break;

			case 4://display buildings
				cout << std::string(5, '\n');
				oSu.DisplayBuildings();
				cout << std::string(2, '\n');
				break;

			case 5://display people
				cout << std::string(5, '\n');
				oSu.DisplayPeople();
				cout << std::string(2, '\n');
				break;

			case 6://do work
				do {
					cout << std::string(5, '\n');
					oSu.DisplayPeople();
					cout << "Enter the number of the person you want to do work." << endl;
					std::cin.clear();
					std::cin.ignore(300, '\n');
					cin >> option;
				} while (cinFail()||option<1||option>oSu.GetNumOfPeople());
				do {
					cout << std::string(5, '\n');
					cout << "How many hours did they work this week?" << endl;
					cin >> hours;
					if (hours > 100 || hours < 0)
					{
						cout << std::string(5, '\n');
						cout << "That is too high or too low. Please pick an amount of hours from 0 to 100." << endl;
					}
				} while (hours > 100 || hours < 0 || cinFail());
				cout << std::string(5, '\n');
				option--;
				oSu.Do_Work(option, hours);
				break;

			case 7://exit
				exit++;
			}
		}
		oSu.Exit();
	return 0;
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