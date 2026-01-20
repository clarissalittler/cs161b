# Makefile for Week 7: Memory Practice
# Just type 'make' to build all examples, 'make clean' to remove binaries

CXX = g++
CXXFLAGS = -Wall -g

PROGRAMS = 01-memory-pitfalls 02-cleanup-patterns \
           03-nullptr-after-delete 04-early-return-cleanup
MINI_PROJECT = mini-project/safe_strings

.PHONY: all clean mini-project valgrind

all: $(PROGRAMS)

mini-project: $(MINI_PROJECT)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

mini-project/safe_strings: mini-project/safe_strings.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Run valgrind on the examples
valgrind: $(PROGRAMS)
	@echo "=== Running valgrind on 01-memory-pitfalls ==="
	valgrind --leak-check=full ./01-memory-pitfalls
	@echo ""
	@echo "=== Running valgrind on 02-cleanup-patterns ==="
	valgrind --leak-check=full ./02-cleanup-patterns

clean:
	rm -f $(PROGRAMS) $(MINI_PROJECT)
