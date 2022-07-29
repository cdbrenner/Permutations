// THIS PROGRAM WILL ONLY WORK UP TO 65 UNIQUE BOOLS DUE TO "<bitset>" LIMITATION

#pragma once

#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include "LinkedBSearchTree.h"

template<class T>
class Permutation
{
    private:
        LinkedBSearchTree<long long> tree;
        LinkedBSearchTree<std::string> stringTree;

    protected:
        static void display(long long& item);

    public:
        void oneConstant(int);
        void twoConstant(int);
        void threeConstant(int);
        void fourConstant(int);
        void printPattern(int);

};
#include "Permutation.cpp"