# /*********************************************************************
# ** Program name:Shopping List
# ** Author: Ethan Dunham
# ** Date: 1/24/17
# ** Description: This is the makefile for shopping list.
# *********************************************************************/
CXX = g++
CXXFlags = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = List.o Item.o Main.o

SRCS = List.cpp Item.cpp Main.cpp

HEADERS = List.hpp Item.hpp

list: 
	g++ -std=c++11 ${SRCS} -o list

clean:
	$(RM) *.o list
