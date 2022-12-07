# Winston Zhang, wyz5rge
# Makefile for Prelab 10
# 22 November 2021

CXX = clang++
CXXFLAGS = -Wall -g

huffmanenc: huffmanenc.o huffmanNode.o heap.o
	$(CXX) $(CXXFLAGS) huffmanenc.o huffmanNode.o heap.o -o a.out
	@echo "done!"

# fileio.o: fileio.cpp
heap.o: heap.cpp huffmanNode.h heap.h
huffmanenc.o: huffmanenc.cpp huffmanNode.h heap.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
