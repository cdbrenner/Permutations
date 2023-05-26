// DIGIT LENGTH OF PERMUTABLE BINARY NUMBER IS THE HEIGHT OF THE TREE

#pragma once
#include "LinkedBTreeNode.h"
#include <iostream>
#include <cmath>

class PermutationTree : public LinkedBTreeNode<char>
{
    private:
        LinkedBTreeNode<char>* m_root_ptr = new LinkedBTreeNode<char>('0',0);
        std::string* m_data;
        std::string* m_sub_data;
        short m_digit_length;
        short m_data_length;
        short m_sub_data_length;
        short m_data_iterator = 0;
        short m_sub_data_iterator = 0;

    public:
        PermutationTree(short);
        // ~PermutationTree();

        void inorder_delete(LinkedBTreeNode<char>*);

        LinkedBTreeNode<char>* get_root();
        std::string* get_data();
        std::string* get_sub_data();
        short get_digit_length();
        short get_data_length();
        short get_sub_data_length();

        void add_node(LinkedBTreeNode<char>*, const char&, bool);
        void build_tree(LinkedBTreeNode<char>*, short, short);
        
        // GIVEN NUMBER OF VARYING BITS THROUGH THE BITSET
        // RETURN THE SUBSET OF PERMUTATIONS
        int nested_summation(short, short);
        int count_sub_set(short);
        void malloc_sub_data(short);
        void add_sub_data(LinkedBTreeNode<char>*, short, short);
        void build_sub_data(short);
};