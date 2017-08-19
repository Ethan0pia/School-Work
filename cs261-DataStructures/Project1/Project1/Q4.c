/* CS261- Assignment 1 - Q.4*/
/* Name: Ethan Dunham
* Date: 4/12/17
 * Solution description: This sorts students based on test score.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
	for (int i = 0; i < n; i++)
	{
		for (int g = i + 1; g < n; g++)
		{
			if (students[g].score < students[i].score)
			{
				struct student temp = students[i];
				students[i] = students[g];
				students[g] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 4;
    /*Allocate memory for n students using malloc.*/
	struct student *students = malloc(n * sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	for (int i = 0; i < 4; i++)
	{
		int v = 1;
		while (v == 1)
		{
			v = 0;
			students[i].id = rand() % 4 + 1;
			students[i].score = rand() % 100;
			if (i != 0)
			{
				for (int o = 0; o < i; o++)
				{
					if (students[o].id == students[i].id)
					{
						v = 1;
					}
				}
			}
		}
	}
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i \n", students[i].id, students[i].score);
	}
    /*Pass this array along with n to the sort() function*/
	sort(students, n);
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < 4; i++)
	{
		printf("Sorted: %i %i \n", students[i].id, students[i].score);
	}

	free(students);
    return 0;
}
