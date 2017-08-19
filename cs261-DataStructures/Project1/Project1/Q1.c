/* CS261- Assignment 1 - Q.1*/
/* Name: Ethan Dunham
* Date: 4/12/17
 * Solution description: This creates 10 students and displays their info.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *students = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	return students;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	for (int i = 0; i < 10; i++)
	{
		int v = 1;
		while (v == 1)
		{
			v = 0;
			students[i].id = rand() % 10 + 1;
			students[i].score = rand() % 100 + 1;
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

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("%i %i \n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min=100, max=0,sum=0;
	double average;
	for (int i = 0; i < 10; i++)
	{
		sum += students[i].score;
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		if (students[i].score < min)
		{
			min = students[i].score;
		}
	}
	average = 1.0*sum / 10;
	printf("Min: %d\n", min);
	printf("Max: %d\n", max);
	printf("Average: %lf\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
