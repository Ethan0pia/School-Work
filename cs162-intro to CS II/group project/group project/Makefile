CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS +=  -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = Paper.o RPSGame.o Rock.o Scissors.o Tool.o play_game.o  
SRCS = Paper.cpp RPSGame.cpp Rock.cpp Scissors.cpp Tool.cpp play_game.cpp 
HEADERS = Paper.hpp RPSGame.hpp Rock.hpp Scissors.hpp Tool.hpp 

all : $(OBJS)
	$(CXX) $(OBJS) -o RPSGame 

$(OBJS) : $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean: 
	rm *.o RPSGame
