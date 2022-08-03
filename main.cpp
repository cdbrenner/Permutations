#include <iostream>
#include <fstream>
#include "LinkedBTreeNode.h"
#include "LinkedBTree.h"
#include "LinkedBSearchTree.h"
#include "Permutation.h"

int main()
{ 
    int size = 0;
    Permutation<int> p;

    // while(size != -1)
    // {
        // std::cout << "Enter size" << std::endl;
        // std::cin >> size;
        // p.oneConstant(size);
        // p.twoConstant(size);
        // p.threeConstant(size);
        // p.fourConstant(size);
        // p.printPattern(size);
    // }

    // p.permutationCreator(4,2,0);
    // p.twoConstant(4);
    p.permutationCreator(5,3,0);
    // p.threeConstant(4);
}