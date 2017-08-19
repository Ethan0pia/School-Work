/*********************************************************************************
**Author: Ethan Dunham
**Date: 7/21/17
**Assignment: Program 2
**Class: CS 344-400
**Discription: This program lets the user play a game with rooms created.
*********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

char *TimeFileName = "currentTime.txt";
pthread_mutex_t TimeFile_Mutex;

struct room
{
	char name[15];
	int totalConnections;
	struct room *connections[6];
	char type[11];
};

struct room rooms[7];
struct room roomsVisited[50];
int steps;
struct room current;

//Opens correct rooms folder
//Source::https://oregonstate.instructure.com/courses/1638966/pages/2-dot-4-manipulating-directories
void findDir()
{
	int newestDirTime = -1; // Modified timestamp of newest subdir examined
	char targetDirPrefix[32] = "dunhamet.rooms."; // Prefix we're looking for
	char newestDirName[256]; // Holds the name of the newest dir that contains prefix
	memset(newestDirName, '\0', sizeof(newestDirName));

	DIR* dirToCheck; // Holds the directory we're starting in
	struct dirent *fileInDir; // Holds the current subdir of the starting dir
	struct stat dirAttributes; // Holds information we've gained about subdir

	dirToCheck = opendir("."); // Open up the directory this program was run in

	if (dirToCheck > 0) // Make sure the current directory could be opened
	{
		while ((fileInDir = readdir(dirToCheck)) != NULL) // Check each entry in dir
		{
			if (strstr(fileInDir->d_name, targetDirPrefix) != NULL) // If entry has prefix
			{
				stat(fileInDir->d_name, &dirAttributes); // Get attributes of the entry

				if ((int)dirAttributes.st_mtime > newestDirTime) // If this time is bigger
				{
					newestDirTime = (int)dirAttributes.st_mtime;
					memset(newestDirName, '\0', sizeof(newestDirName));
					strcpy(newestDirName, fileInDir->d_name);
				}
			}
		}
	}

	//convert files to structs to use for game
	int i;
	const char* names[10];
	//checks directory for each room name file
	names[0] = "Hottub"; names[1] = "Bathroom"; names[2] = "Hall"; names[3] = "Parlor"; names[4] = "Kitchen";
	names[5] = "Livingroom"; names[6] = "Bedroom"; names[7] = "dungeon"; names[8] = "Study"; names[9] = "Library";
	int f = 0;
	for (i = 0; i < 10; i++) {
		FILE *temp;
		char tempName[256];
		strcpy(tempName, "./");
		strcat(tempName, newestDirName);
		strcat(tempName, "/");
		strcat(tempName, names[i]);
		//opens that file based on directory found previously
		temp = fopen(tempName, "r");
		if (temp != NULL) {
			char line[200];
			//gets name line
			fgets(line, 200, temp);
			strtok(line, "\n");
			strcpy(rooms[f].name, &line[11]);

			fgets(line, 200, temp);
			int x = 0;
			while (line[0] == 'C') {
				//gets connections
				strcpy(line, &line[14]);
				x++;
				//increases connections
				rooms[f].totalConnections++;
				fgets(line, 200, temp);
			}
			//gets room type
			strtok(line, "\n");
			strcpy(rooms[f].type, &line[11]);
			f++;
			fclose(temp);
		}
	}

	for (i = 0; i < 7; i++) {
		FILE *temp;
		char tempName[256];
		strcpy(tempName, "./");
		strcat(tempName, newestDirName);
		strcat(tempName, "/");
		strcat(tempName, rooms[i].name);
		//opens that file based on directory found previously
		temp = fopen(tempName, "r");
		if (temp != NULL) {
			char line[200];
			//gets name line
			fgets(line, 200, temp);
			fgets(line, 200, temp);
			int x = 0;
			while (line[0] == 'C') {
				//gets connections
				strcpy(line, &line[14]);
				strtok(line, "\n");
				int g;
				for (g = 0; g < 7; g++) {
					if (strcmp(line, rooms[g].name) == 0) {
						rooms[i].connections[x] = &rooms[g];
						fgets(line, 200, temp);
						x++;
					}
				}
			}
			fclose(temp);
		}
	}
}

//finds the start location
void findStart() {
	int i;
	for (i = 0; i < 7; i++) {
		if (strcmp(rooms[i].type, "START_ROOM") == 0) {
			current = rooms[i];
		}
	}
}

//Time keeping functions
//Source: https://github.com/zainkai/CS344/blob/master/Assignment_2/turkingk.adventure.c
//Source: http://stackoverflow.com/questions/5141960/get-the-current-time-in-c
void* CreateCurrentTimeFile()
{
	char TimeStr[256];
	time_t CurrTime;
	struct tm * TimeInfo;
	FILE *TimeFile;

	memset(TimeStr, '\0', sizeof(TimeStr)); // clear time string of garbage.

	time(&CurrTime); // get current time.
	TimeInfo = localtime(&CurrTime); // put time into an easily accessable struct.
	strftime(TimeStr, 256, "%I:%M%P %A, %B %d, %Y", TimeInfo); // format string.
															   //printf("\n%s\n\n",TimeStr);

	TimeFile = fopen(TimeFileName, "w");//Will create or overwrite a file
	fprintf(TimeFile, "%s\n", TimeStr); // print time to file.
	fclose(TimeFile);

	return NULL;
}

// DESC: reads in a file and display the current time.
//Source: https://github.com/zainkai/CS344/blob/master/Assignment_2/turkingk.adventure.c
void ReadCurrentTimeFile()
{
	char Buffer[256];
	FILE *TimeFile;

	memset(Buffer, '\0', sizeof(Buffer)); // clear buffer of garbage.

	TimeFile = fopen(TimeFileName, "r"); // readin a file.
	if (TimeFile == NULL) {// check if the file exists.
		printf("%s was not accessed.\n", TimeFileName);
		return;
	}

	//read in each line in the file (there should only be one.)
	while (fgets(Buffer, 256, TimeFile) != NULL) {
		printf("\n%s\n", Buffer); // print the line.
	}
	fclose(TimeFile);
}

// DESC: creates a seperate thread to write a file containing local time.
//Source: https://github.com/zainkai/CS344/blob/master/Assignment_2/turkingk.adventure.c
bool TimeThread()
{
	pthread_t WriteTimeFile_Thread; // holder for the thread that will contain the function.
	pthread_mutex_lock(&TimeFile_Mutex); // this thread cannot be used untill its done running.

										 // if something went wrong dont continue.
	if (pthread_create(&WriteTimeFile_Thread, NULL, CreateCurrentTimeFile, NULL) != 0) { // begin running write file function.
		printf("Error from thread!");
		return false;
	}

	//once done unlock the mutex.
	pthread_mutex_unlock(&TimeFile_Mutex);
	// prevent runnaway processes.
	pthread_join(WriteTimeFile_Thread, NULL);
	return true;
}

//player interface should list where the player current is, and list the possible 
//connections that can be followed. It should also then have a prompt.
/*
CURRENT LOCATION: XYZZY
POSSIBLE CONNECTIONS: PLOVER, Dungeon, twisty.
WHERE TO? >
*/
//prints the information for the room
void print() {
	printf("\nCURRENT LOCATION: %s\n", current.name);
	printf("POSSIBLE CONNECTIONS: ");
	int i;
	//prints possible connections
	for (i = 0; i < current.totalConnections-1; i++) {
		strtok(current.connections[i], "\n");
		printf("%s, ", current.connections[i]);
	}
	strtok(current.connections[i], "\n");
	printf("%s.\nWHERE TO? \>", current.connections[i]);
}

//checks for win state
bool winState() {
	if (strcmp(current.type, "END_ROOM") == 0) {
		return true;
	}
	return false;
}

//takes in user input and makes the appropriate move.
void makeMove() {
	char *line = NULL;
	size_t size;
	getline(&line, &size, stdin);
	strtok(line, "\n");
	int i;
	//searches for room based on user input
	for (i = 0; i < current.totalConnections; i++) {
		if (strcmp(line, current.connections[i]) == 0) {
			//changes current location
			setCurrent(line);
			//keeps track of score/locations visited
			roomsVisited[steps] = current;
			steps++;

			return;
		}
	}
	//if the user enters time, it displays time without incrementing turns
	if (strcmp(line, "time") == 0) {
		ReadCurrentTimeFile();
		return;
	}

	//had to split it up to make it display correctly.
	printf("\nHUH? I DON");
	printf("%c", 39);
	printf("T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
	print(current);
	makeMove();
}

//sets current room pointer
void setCurrent(char* newRoom) {
	int i;
	for (i = 0; i < 7; i++) {
		if (strcmp(newRoom, rooms[i].name) == 0) {
			current = rooms[i];
			return;
		}
	}
}


int main() {
	//sorts rooms into structs
	findDir();

	TimeThread();
	//finds the starting location
	findStart();
	//initializes steps to 0
	steps = 0;
	//plays game until win state is reached
	while (winState() == false) {
		print();
		makeMove();
	}
	//prints score and congrats
	printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\nYOU TOOK ");
	printf("%d STEPS. YOUR PATH TO VICTORY WAS:\n", steps);
	//prints steps you took
	int x;
	for (x = 0; x < steps;x++) {
		printf("%s\n", roomsVisited[x].name);
	}
	//returns 0
	return 0;
}