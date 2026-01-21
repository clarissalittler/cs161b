# Makefile for Week 10: ncurses + Templates

CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = -lncurses

PROGRAMS = game

.PHONY: all clean

all: $(PROGRAMS)

game: main.cpp game.cpp game.h utils.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp game.cpp $(LDFLAGS)

clean:
	rm -f $(PROGRAMS) save.txt
