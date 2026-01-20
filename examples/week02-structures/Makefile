# Makefile for Week 2: Structures
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-2d-arrays 02-structs 03-arrays-of-structs \
           04-2d-array-row-sum 05-struct-initialization 06-array-of-structs-search
MINI_PROJECT = mini-project/contact_book

.PHONY: all clean mini-project

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/contact_book: mini-project/contact_book.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
