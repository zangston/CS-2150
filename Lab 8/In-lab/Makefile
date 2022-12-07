CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = mergeSort.o testMergeSort.cpp

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~ a.out
