/* CS261- Assignment 1 - Q.3*/
/* Name: Ethan Dunham
* Date: 4/12/17
 * Solution description: This sorts using bubblesort.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	for (int i = 0; i < n; i++)
	{
		for (int g = i+1; g < n; g++)
		{
			if (number[g] < number[i])
			{
				int temp = number[i];
				number[i] = number[g];
				number[g] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int *arr = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
    /*Print the contents of the array.*/
	for (int i = 0; i < n; i++)
	{
		printf("  %d\n",arr[i]);
	}
    /*Pass this array along with n to the sort() function of part a.*/
	sort(arr, n);
    /*Print the contents of the array.*/    
	for (int i = 0; i < n; i++)
	{
		printf("Sorted: %d\n", arr[i]);
	}
    return 0;
}
