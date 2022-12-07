# Winston Zhang, wyz5rge
# Makefile for in-lab 10
# 23 November 2021

CXX = clang++
CXXFLAGS = -Wall -g

huffmandec: huffmandec.o huffmanNode.o
	$(CXX) $(CXXFLAGS) huffmandec.o huffmanNode.o -o a.out

huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h

# don't think we need this
#inlab-skeleton.o: inlab-skeleton.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
