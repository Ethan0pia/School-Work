/*********************************************************************************
**Author: Ethan Dunham
**Date: 7/21/17
**Assignment: Program 2
**Class: CS 344-400
**Discription: This program makes 7 rooms and connects them.
*********************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

//struct with name, array of 6 possible connections, and type	done
struct Room {
	char name[24];
	int totalConnections;
	struct Room* connections[6];
	char type[11];
};

bool IsGraphFull(struct Room*);
void AddRandomConnection(struct Room*, struct Room*);
struct Room* GetRandomRoom(struct Room*);
bool CanAddConnectionFrom(struct Room, struct Room);
void ConnectRoom(struct Room*, struct Room*);
bool IsSameRoom(struct Room, struct Room);
void printRooms(struct Room *);

// Create all connections in graph		done
int main() {
	srand(time(NULL));

	struct Room rooms[7];

	//adds room names
	const char* names[10];
	names[0] = "Hottub"; names[1] = "Bathroom"; names[2] = "Hall"; names[3] = "Parlor"; names[4] = "Kitchen";
	names[5] = "Livingroom"; names[6] = "Bedroom"; names[7] = "dungeon"; names[8] = "Study"; names[9] = "Library";
	//array of names used
	int namesUsed[7] = { 10,10,10,10,10,10,10 };

	int i;
	for (i=0; i < 7; i++) {
		int name = rand() % 10;
		//check if name has been used
		int y=0;
		while (y<7) {
			if (namesUsed[y] == name) {
				name = rand() % 10;
				y = 0;
			}
			else if (namesUsed[y] == 10) {
				namesUsed[y] = name;
				break;
			}
			else {
				y++;
			}
		}

		strcpy(rooms[i].name, names[name]);
		rooms[i].totalConnections = 0;
	}

	//set random start room
	struct Room* start = GetRandomRoom(rooms);
	strcpy(start->type, "START_ROOM");

	//set random end room
	struct Room* end = GetRandomRoom(rooms);
	//verify end room is not the same as start room
	while (strcmp(start->name, end->name)==0) {
		end = GetRandomRoom(rooms);
	}
	strcpy(end->type, "END_ROOM");
	int r;
	for (r = 0; r < 7; r++) {
		//add room type if not beginning or end
		if (strcmp(rooms[r].type, "START_ROOM")!=0 && strcmp(rooms[r].type, "END_ROOM") != 0) {
			strcpy(rooms[r].type, "MID_ROOM");
		}
	}
	int d = 0;
	while (IsGraphFull(rooms)==false)
	{
		AddRandomConnection(rooms, &rooms[d]);
		d++;
		if (d > 6) {
			d = 0;
		}
	}
	printRooms(rooms);
	return 0;
}

// Returns true if all rooms have 3 to 6 outbound connections, false otherwise		done
bool IsGraphFull(struct Room* rooms)
{
	int i;
	for (i = 0; i < 7; i++) {
		if (rooms[i].totalConnections < 3) {
			return false;
		}
	}
	return true;
}

// Adds a random, valid outbound connection from a Room to another Room		Done
void AddRandomConnection(struct Room* rooms, struct Room* room)
{
	struct Room* A = room;
	struct Room* B = GetRandomRoom(rooms);
	int i = 0;
	while (CanAddConnectionFrom(*A, *B)==false && i<20){
		B = GetRandomRoom(rooms);
		//stop infinite loop if no connection possible after 20 random rooms
		i++;
	}
	//connects the rooms if possible
	if (CanAddConnectionFrom(*A, *B)==true)
	{
		ConnectRoom(A, B);
	}
}

// Returns a random Room, does NOT validate if connection can be added		done
struct Room* GetRandomRoom(struct Room* rooms)
{
	int random = rand() % 7;
	return &(rooms[random]);
}

// Returns true if a connection can be added from Room x, false otherwise		done
bool CanAddConnectionFrom(struct Room x, struct Room y)
{
	if (IsSameRoom(x, y)==false && x.totalConnections < 6 && y.totalConnections < 6) {
		int i;
		for (i=0; i < x.totalConnections; i++) {
			if (IsSameRoom((*x.connections[i]), y)==true) {
				return false;
			}
		}
		return true;
	}
	return false;
}

// Connects Rooms x and y together, does not check if this connection is valid		done
void ConnectRoom(struct Room* x, struct Room* y)
{
	x->connections[x->totalConnections] = y;
	y->connections[y->totalConnections] = x;
	x->totalConnections= x->totalConnections + 1;
	y->totalConnections = y->totalConnections + 1;
}

// Returns true if Rooms x and y are the same Room, false otherwise		done
bool IsSameRoom(struct Room x, struct Room y)
{
	if (strcmp(x.name, y.name) == 0)
		return true;
	return false;
}



//prints rooms to files			done
void printRooms(struct Room *rooms) {

	//create new directory for rooms
	char folderName[50];
	memset(folderName, '\0', sizeof(folderName));
	sprintf(folderName, "./dunhamet.rooms.%d", getpid());
	mkdir(folderName, 0777);

	FILE *roomFile;

	//creates rooms
	int i;
	for (i = 0; i < 7; i++) {
		char tempName[256];
		strcpy(tempName, folderName);
		strcat(tempName, "/");
		strcat(tempName, rooms[i].name);
		roomFile = fopen(tempName, "w");

		//prints room name and connections
		fprintf(roomFile, "ROOM NAME: %s\n", rooms[i].name);
		int j;
		for (j = 0; j < rooms[i].totalConnections; j++) {
			fprintf(roomFile, "CONNECTION %d: %s\n", j + 1, rooms[i].connections[j]->name);
		}

		//adds room type
		fprintf(roomFile, "ROOM TYPE: %s\n", rooms[i].type);
		
		fclose(roomFile);
	}
}