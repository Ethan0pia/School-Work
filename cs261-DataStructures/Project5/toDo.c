/*
 * CS 261 Assignment 5
 * Name: Ethan Dunham
 * Date: 5/22/17
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	int(*functionPtr)(void*, void*);
	functionPtr = &taskCompare;
	if (command == 'l')
	{
		char name[128];
		printf("Enter the file name:");
		scanf("%s", name);
		while (getchar() != '\n');
		FILE* file;
		file = fopen(name, "r");
		listLoad(list, file);
		fclose(file);
		printf("Tasks have been loaded. \n");
	}
	else if (command == 's')
	{
		char name[128];
		printf("Enter the file name:");
		scanf("%s", name);
		while (getchar() != '\n');
		FILE* file;
		file = fopen(name, "w");
		listSave(list, file);
		fclose(file);
		printf("Tasks have been saved. \n");
	}
	else if (command == 'a')
	{
		char com[TASK_NAME_SIZE];
		int n;
		printf("Enter the task name:");
		scanf("%[^\n]s", com);
		while (getchar() != '\n');
		printf("Enter the task's Priority:");
		scanf("%d", &n);
		while (getchar() != '\n');
		Task * newTask = taskNew(n, com);
		dyHeapAdd(list, newTask, functionPtr);
		printf("Task has been added: %s\n", com);
	}
	else if (command == 'g')
	{
		Task* temp = dyHeapGetMin(list);
		if (temp == 0) {
			printf("Your list is empty!\n");
		}
		else {
			printf("The first task is: %s\n", temp->name);
		}
	}
	else if (command == 'r') {
		Task* temp = dyHeapGetMin(list);
		if (temp == 0) {
			printf("Your list is empty!\n");
		}
		else {
			printf("The first task, %s, has been removed.\n", temp->name);
			dyHeapRemoveMin(list, functionPtr);
			free(temp);
		}
	}
	else if (command == 'p')
		listPrint(list);
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
	for (int i = 0; i < dySize(list); i++) {
		Task* temp = dyGet(list, i);
		free(temp);
	}
    dyDelete(list);
    return 0;
}