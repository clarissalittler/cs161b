# Makefile for Week 5: Integration
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-menu-loop 02-load-work-save 03-separate-compilation/demo \
           inventory_manager grade_book
MINI_PROJECT = mini-project/finance_tracker

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

03-separate-compilation/demo: 03-separate-compilation/main.cpp \
                              03-separate-compilation/math_utils.cpp \
                              03-separate-compilation/math_utils.h
	$(CXX) $(CXXFLAGS) -o $@ 03-separate-compilation/main.cpp \
		03-separate-compilation/math_utils.cpp

mini-project/finance_tracker: mini-project/finance_tracker.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
	rm -f inventory.dat gradebook.dat items.txt  # Clean up data files
