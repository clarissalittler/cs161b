# Makefile for Week 10: Templates and STL
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

PROGRAMS = 01-function-templates 02-class-templates 03-stl-intro \
           04-template-max 05-template-swap 06-stl-vector-basics
MINI_PROJECT = mini-project/stats_library

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/stats_library: mini-project/stats_library.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
