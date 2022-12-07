# Winston Zhang, wyz5rge
# Makefile for In-lab 11
# 30 November 2021

CXX = clang++
CXXFLAGS = -Wall -g -o2
DOX = doxygen Doxyfile

traveling: traveling.o middleearth.o
	$(CXX) $(CXXFLAGS) traveling.o middleearth.o -o a.out
	$(DOX)

middleearth.o: middleearth.cpp middleearth.h
traveling.o: traveling.cpp middleearth.h

.PHONY: clean
clean:
	-rm -r doc -f *.o *~ a.out
