# Winston Zhang, wyz5rge
# Makefile for Prelab 11
# 30 November 2021

CXX = clang++
CXXFLAGS = -Wall -g
DOX = doxygen Doxyfile

topological: topological.o
	$(CXX) $(CXXFLAGS) topological.o -o a.out
	$(DOX)

#middleearth.o: middleearth.cpp middleearth.h
topological.o: topological.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
