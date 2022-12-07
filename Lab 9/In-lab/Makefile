# Winston Zhang, wyz5rge
# Makefile for In-lab 9
# 16 November 2021

# clang instead of clang++ because we're working with C instead of C++
CXX = clang
CXXFLAGS = -Wall -g

linkedlist: linkedlist.o
	$(CXX) $(CXXFLAGS) linkedlist.o -o a.out
	@echo "done!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

linkedlist.o: linkedlist.c
