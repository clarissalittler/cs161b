# Makefile for Week 8: Data Structures
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-linked-list 02-stack 03-queue
MINI_PROJECT = mini-project/postfix_calculator

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/postfix_calculator: mini-project/postfix_calculator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
