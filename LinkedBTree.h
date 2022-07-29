#pragma once

#include <algorithm>
#include "TreeInterface.h"
#include "LinkedBTreeNode.h"
#include "NotFoundExcep.h"

 template<class T> 
 class LinkedBTree: public TreeInterface<T>
 { 
    protected: 
        LinkedBTreeNode<T>* rootPtr = nullptr;

    public:
        LinkedBTree();
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        T getRootData() const;
        virtual bool add(const T& newData) {return false;}
        virtual bool remove(const T& data) {return false;}
        void clear();
        virtual T getEntry(const T& anEntry) const {return anEntry;}
        virtual bool contains(const T& anEntry) const {return false;}
        void preorderTraverse(void visit(T&)) const;
        void inorderTraverse(void visit(T&)) const;
        void postorderTraverse(void visit(T&)) const;
        ~LinkedBTree();

    protected:
        int getHeightHelper(LinkedBTreeNode<T>* subTreePtr) const;
        int getNumberOfNodesHelper(LinkedBTreeNode<T>* subTreePtr) const;
        LinkedBTreeNode<T>* copyTree(const LinkedBTreeNode<T>* oldTreeRootPtr) const;
        void destroyTree(LinkedBTreeNode<T>* subTreePtr);
        void preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
        void inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
        void postorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
 };
 #include "LinkedBTree.cpp"