# Makefile for Prelab 9

CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = timer.o threexplusone.o threexinput.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "done!"

threexinput.o: threexinput.cpp timer.h
timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
