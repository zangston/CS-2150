CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2
SANITIZE = -fsanitize=address -fno-omit-frame-pointer
DEBUG=-g

TreeCalcTest: TreeCalc.o TreeCalcTest.o TreeNode.o
	#$(CXX) $(SANITIZE) $(DEBUG) TreeCalc.o TreeCalcTest.o TreeNode.o -o a.out
	$(CXX) $(DEBUG) TreeCalc.o TreeCalcTest.o TreeNode.o -o a.out
	@echo "done"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h

