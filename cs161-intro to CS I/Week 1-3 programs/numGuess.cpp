/*********************************************************************
** Author: Ethan Dunham
** Date: 10/08/16
** Description: This program will play a guessing game with a number
*********************************************************************/

#include <iostream>
using namespace std;

main()
{
	float numberToGuess, numGuess, numOfLoops = 1;
	//Start number of loops at 1 because last guess wont make loop add 1 to value.
	cout << "Enter the number for the player to guess."<< endl;
	cin >> numberToGuess;//gets number that needs to be guessed.
	cout << "Enter your guess." << endl;
	cin >> numGuess;//takes number from player.
	while (numGuess != numberToGuess)//loop to keep player guessing until correct.
	{
		numOfLoops++;//adds to number of loop to keep track

		if (numGuess > numberToGuess)//if guess is too high, it outputs too high.
		{
			cout << "Too High - try again." << endl;
			cin >> numGuess;
		}

		else if (numGuess < numberToGuess)//or if too low it outputs too low.
		{
			cout << "Too Low - try again." << endl;
			cin >> numGuess;
		}
	}
	cout << "You guessed it in " << numOfLoops << " tries." << endl;
	//if it reaches this line, it means guess was correct.

	return 0;
}