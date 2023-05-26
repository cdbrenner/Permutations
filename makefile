x: main.cpp permutation_tree.o PrecondViolatedExcep.o NotFoundExcep.o Permutation.h TreeInterface.h LinkedBTreeNode.h LinkedBTree.h LinkedBSearchTree.h permutation_tree.h
	g++ -o x main.cpp permutation_tree.o PrecondViolatedExcep.o NotFoundExcep.o

permutation_tree.o: permutation_tree.cpp
	g++ -c permutation_tree.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -c PrecondViolatedExcep.cpp

NotFoundExcep.o: NotFoundExcep.cpp NotFoundExcep.h
	g++ -c NotFoundExcep.cpp

clean:
	rm -f x *.o