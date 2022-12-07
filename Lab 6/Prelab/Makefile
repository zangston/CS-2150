CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2 -g

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	$(CXX) wordPuzzle.o hashTable.o timer.o -o a.out
	@echo "done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

getWordInGrid.o: getWordInGrid.cpp
hashTable.o: hashTable.cpp hashTable.h
primenumber.o: primenumber.cpp
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
