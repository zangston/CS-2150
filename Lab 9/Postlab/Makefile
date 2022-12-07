# Winston Zhang, wyz5rge
# Makefile for postlab 9
# 17 November 2021

CXX = clang++
CXXFLAGS = -Wall -g #-lrt
AS = nasm
ASFLAGS = -f elf64 -g

testBinarySearch: testBinarySearch.o timer.o binarySearch.o
	$(CXX) $(CXXFLAGS) testBinarySearch.o timer.o binarySearch.o
	@echo "done!"


testBinarySearch.o: testBinarySearch.cpp timer.h
timer.o: timer.cpp timer.h
binarySearch.o: binarySearch.s

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
