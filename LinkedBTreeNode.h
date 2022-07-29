#pragma once

template<class T> 
class LinkedBTreeNode
{ 
  private: 
    T item;  
    LinkedBTreeNode<T>* leftChildPtr = nullptr;  
    LinkedBTreeNode<T>* rightChildPtr = nullptr;
  
  public: 
    LinkedBTreeNode();
    LinkedBTreeNode(const T& newData);
    LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right);
    void setItem(const T& newData);
    T getItem() const;
    bool isLeaf() const;
    LinkedBTreeNode<T>* getLeftChildPtr();
    LinkedBTreeNode<T>* getRightChildPtr();
    void setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr);
    void setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr);
};
#include "LinkedBTreeNode.cpp"