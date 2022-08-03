// THIS PROGRAM WILL ONLY WORK UP TO 65 UNIQUE BOOLS DUE TO "<bitset>" LIMITATION

#pragma once

#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <list>
#include "LinkedBSearchTree.h"

template<class T>
class Permutation
{
    private:
        LinkedBSearchTree<long long> tree;
        LinkedBSearchTree<std::string> stringTree;
        std::list<int> m_permutation;
        std::list<int>::iterator m_position;
        std::list<int>::iterator m_counter;

    protected:
        static void display(long long& item);

    public:
        void permutationCreator(int,int,int);
        void oneConstant(int);
        void twoConstant(int);
        void threeConstant(int);
        void fourConstant(int);
        void printPattern(int);

};
#include "Permutation.cpp"