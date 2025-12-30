# Makefile for Week 5: Integration
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = inventory_manager grade_book
MINI_PROJECT = mini-project/finance_tracker

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/finance_tracker: mini-project/finance_tracker.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
	rm -f inventory.dat gradebook.dat  # Clean up data files
