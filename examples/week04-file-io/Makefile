# Makefile for Week 4: File I/O
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-reading-files 02-writing-files 03-parsing \
           04-open-check 05-read-lines 06-write-append 07-parse-delimited
MINI_PROJECT = mini-project/todo_list

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/todo_list: mini-project/todo_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
	rm -f output.txt students.txt data.csv log.txt  # Clean up generated files
