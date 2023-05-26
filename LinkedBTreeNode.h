// MIGHT WANT TO REMOVE DATA LIKE "BITSET" AND "NODE-DEPTH", ETC..., AND WRAP THEM INTO A CLASS NAMED NODE_DATA
// SINCE THEY ARE NOT INHERENT TO THE FUNCTIONALITY OF A NODE. FOR NOW, I'M BEING LAZY AND DECLARING DATA HERE...

#pragma once
#include <iostream>

template<class T> 
class LinkedBTreeNode
{ 
  private: 
    T item;
    LinkedBTreeNode<T>* leftChildPtr = nullptr;  
    LinkedBTreeNode<T>* rightChildPtr = nullptr;
    
    //START: DATA ATTRIBUTES THAT I SHOULD MOVE TO A NODE_DATA CLASS IN THE FUTURE
    std::string m_bitset = "";
    short m_node_depth = -1;
    // short bool_false_count = 0;
    // short bool_true_count = 0;
    //END
  
  public: 
    LinkedBTreeNode();
    LinkedBTreeNode(const T& newData);
    LinkedBTreeNode(const T& newData, short);
    LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right);

    void set_bitset(std::string);
    std::string get_bitset();

    void set_node_depth(short);
    short get_node_depth();
    void setItem(const T& newData);
    T getItem() const;
    bool isLeaf() const;
    LinkedBTreeNode<T>* getLeftChildPtr();
    LinkedBTreeNode<T>* getRightChildPtr();
    void setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr);
    void setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr);
};
#include "LinkedBTreeNode.cpp"