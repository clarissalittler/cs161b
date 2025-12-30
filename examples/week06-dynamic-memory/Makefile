# Makefile for Week 6: Dynamic Memory
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-new-delete 02-dynamic-arrays 03-2d-dynamic
MINI_PROJECT = mini-project/image_processor

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/image_processor: mini-project/image_processor.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
