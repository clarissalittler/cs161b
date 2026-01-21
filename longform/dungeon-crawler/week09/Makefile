# Makefile for Week 09: Debugging

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = game

.PHONY: all clean debug

all: $(PROGRAMS)

game: main.cpp game.cpp game.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp game.cpp

debug: main.cpp game.cpp game.h
	$(CXX) $(CXXFLAGS) -DDEBUG -o game_debug main.cpp game.cpp

clean:
	rm -f $(PROGRAMS) game_debug save.txt
