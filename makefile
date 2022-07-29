x: main.cpp PrecondViolatedExcep.o NotFoundExcep.o Permutation.h TreeInterface.h LinkedBTreeNode.h LinkedBTree.h LinkedBSearchTree.h
	g++ -o x main.cpp PrecondViolatedExcep.o NotFoundExcep.o

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -c PrecondViolatedExcep.cpp

NotFoundExcep.o: NotFoundExcep.cpp NotFoundExcep.h
	g++ -c NotFoundExcep.cpp

clean:
	rm -f x *.o