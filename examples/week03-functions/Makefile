# Makefile for Week 3: Functions
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-decomposition 02-refactoring 03-recursion-basics \
           04-function-overloading 05-default-arguments \
           06-const-references 07-function-pointers
MINI_PROJECT = mini-project/grade_calculator

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/grade_calculator: mini-project/grade_calculator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
