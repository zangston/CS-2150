CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = linearSearch.o testLinearSearch.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	@echo "done"

clean:
	-rm -f *.o *~ a.out
