CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = mathlib.o mathfun.cpp

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~ a.out
