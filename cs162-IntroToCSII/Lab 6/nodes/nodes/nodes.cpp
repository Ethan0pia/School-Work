/*********************************************************************
** Program name:Nodes
** Author: Ethan Dunham
** Date: 2/17/17
** Description: This program demonstrates the understanding of nodes.
*********************************************************************/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

bool cinFail();
//structures
struct node
{
	int value;
	node *next;

	node(int value1, node *next1 = NULL)
	{
		value = value1;
		next = next1;
	}
};

//main
int main()
{
	char again;
	do {
		node *head = NULL;
		node *addNode = NULL;
		node *pointer;
		node *tail = NULL;
		char cont;
		char hOrT;
		int value;
		int loops = 0;
		do {
			do {
				cout << "Please enter a number: ";
				cin >> value;
			} while (cinFail());
			do {
				cout << "Do you want another number? (y or n):";
				cin >> cont;
			} while (cinFail() || (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n'));
			if (head == NULL)
			{
				head = new node(value);
				tail = head;
			}
			else
			{
				tail = head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = new node(value);
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
			}
		} while (cont == 'Y' || cont == 'y');
			
			cout << "Your linked list is: ";
			pointer = head;
			while (pointer != NULL)
			{
				cout << pointer->value << ' ';
				pointer = pointer->next;
			}
				do {
					cout << "\nDo you want to do get head or tail node value? (h or t): ";
					cin >> hOrT;
				} while ((hOrT != 'H' && hOrT != 'h' && hOrT != 't' && hOrT != 'T') || cinFail());
				if (hOrT == 'H' || hOrT == 'h')
				{
					cout << head->value;
				}
				else
				{
					cout << tail->value;
				}

				do {
					cout << "\nDo you want to delete head or tail node? (h or t): ";
					cin >> hOrT;
				} while ((hOrT != 'H' && hOrT != 'h' && hOrT != 't' && hOrT != 'T') || cinFail());
				if (hOrT == 'H' || hOrT == 'h')//delete head
				{
					head = head->next;
				}
				else//delete tail
				{
					if (head->next == NULL)
					{
						tail = head->next;
						head = head->next;
					}
					else
					{
						pointer = head;
						while (pointer->next != NULL)
						{
							pointer = pointer->next;
							if (pointer->next->next == NULL)
							{
								pointer->next = NULL;
							}
						}
						pointer = head;
						while (pointer->next != NULL)
						{
							pointer = pointer->next;
							tail = pointer;
						}
					}
				}

				if (hOrT == 'H' || hOrT == 'h')
				{
					if (head == NULL)
					{
						cout << "The list is empty." << endl;
					}
					else
					{
						cout << "The new head value is: " << head->value << endl;
					}
				}
				else
				{
					if (tail == NULL)
					{
						cout << "The list is empty." << endl;
					}
					else
					{
						cout << "The new tail value is: " << tail->value << endl;
					}
				}
		do {
			cout << "Do you want to do this again? (y or n):";
			cin >> again;
		} while (cinFail() || (again != 'Y' && again != 'y' && again != 'N' && again != 'n'));
	} while (again == 'Y' || again == 'y');
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