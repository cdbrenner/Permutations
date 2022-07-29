#pragma once

#include "LinkedBTreeNode.h"
#include "LinkedBTree.h"
#include "NotFoundExcep.h"

template<class T> 
class LinkedBSearchTree: public LinkedBTree<T>
{ 
    protected:
        LinkedBTreeNode<T>* placeNode(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr);
        LinkedBTreeNode<T>* removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessful);
        LinkedBTreeNode<T>* removeNode(LinkedBTreeNode<T>* nodePtr);
        LinkedBTreeNode<T>* removeLeftmostNode(LinkedBTreeNode<T>*, T& inorderSuccessor);
        LinkedBTreeNode<T>* findNode(LinkedBTreeNode<T>* treePtr, const T& target) const;

    public: 
        LinkedBSearchTree();
        LinkedBSearchTree(const T&);
        bool add(const T&) override;
        bool remove(const T&) override; 
        T getEntry(const T&) const override;
        bool contains(const T&) const override; 
        ~LinkedBSearchTree();
};
#include "LinkedBSearchTree.cpp"