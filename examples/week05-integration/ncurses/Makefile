# Makefile for optional ncurses examples
# Build from this folder: make

CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = -lncurses

PROGRAMS = 01-hello 02-input 03-menu

.PHONY: all clean

all: $(PROGRAMS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(PROGRAMS)
