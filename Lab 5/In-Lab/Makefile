CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2
SANITIZE= -fsanitize=address -fno-omit-frame-pointer
DEBUG=-g

BSTPathTest: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) BinaryNode.o BinarySearchTree.o BSTPathTest.o -o a.out
	@echo "done"

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
