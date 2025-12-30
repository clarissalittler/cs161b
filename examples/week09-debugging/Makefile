# Makefile for Week 9: Debugging
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
# Note: -g flag for debug symbols (needed for GDB)
CXXFLAGS = -Wall -g

PROGRAMS = 01-common-bugs 02-gdb-practice
MINI_PROJECT = mini-project/buggy_sort mini-project/sort_solution

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/buggy_sort: mini-project/buggy_sort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/sort_solution: mini-project/sort_solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
