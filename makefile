x: main.cpp permutation_tree.o permutation_activator.o LinkedBTreeNode.h permutation_tree.h permutation_activator.h
	g++ -o x main.cpp permutation_tree.o permutation_activator.o

permutation_tree.o: permutation_tree.cpp
	g++ -c permutation_tree.cpp

permutation_activator.o: permutation_activator.cpp
	g++ -c permutation_activator.cpp

clean:
	rm -f x *.o