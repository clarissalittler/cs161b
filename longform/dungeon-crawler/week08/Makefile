# Makefile for Week 08: Linked Lists

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = game

.PHONY: all clean

all: $(PROGRAMS)

game: main.cpp game.cpp game.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp game.cpp

clean:
	rm -f $(PROGRAMS) save.txt
