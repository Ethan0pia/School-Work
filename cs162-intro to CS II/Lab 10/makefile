# /*********************************************************************
# ** Program name:
# ** Author: Ethan Dunham
# ** Date: /17
# ** Description: This is the makefile for
# *********************************************************************/
CXX = g++
CXXFlags = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += .g
LDFLAGS = -lboost_date_time

OBJS = "files".o "files".o

SRCS = "files".cpp "files".cpp

HEADERS = "files".hpp

"Program Name": 
	${CXX} ${LDFLAGS} ${OBJS} -o "Program Name"

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	$(RM) *o "Program Name"
