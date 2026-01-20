# Makefile for Week 0: Basics
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

# List of all programs to build
PROGRAMS = 01-hello 02-input-output 03-loops 04-arrays \
           05-input-two-ints 06-while-sentinel 07-array-sum-average \
           08-conditionals 09-switch 10-input-validation
MINI_PROJECT = mini-project/number_cruncher

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

# Pattern rule: how to build any program from its .cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Special rule for the mini-project (different directory)
mini-project/number_cruncher: mini-project/number_cruncher.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
