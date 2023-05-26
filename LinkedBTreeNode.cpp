#include "LinkedBTreeNode.h"

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode() {}

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData)
    : item(newData) {}

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData, short node_depth)
    : item(newData), m_node_depth(node_depth) {}

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right)
    : item(newData), leftChildPtr(left), rightChildPtr(right) {}

template<class T>
void LinkedBTreeNode<T>::set_bitset(std::string parent_bit_set)
{
    m_bitset = parent_bit_set + (char)item;
}

template<class T>
std::string LinkedBTreeNode<T>::get_bitset()
{
    return m_bitset;
}

template<class T>
void LinkedBTreeNode<T>::set_node_depth(short depth)
{
    m_node_depth = depth;
}

template<class T>
short LinkedBTreeNode<T>::get_node_depth()
{
    return m_node_depth;
}

template<class T>
void LinkedBTreeNode<T>::setItem(const T& newData)
{
    item = newData;
}

template<class T>
T LinkedBTreeNode<T>::getItem() const
{
    return item;
}

template<class T>
bool LinkedBTreeNode<T>::isLeaf() const
{
    return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}

template<class T>
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getLeftChildPtr()
{
    return leftChildPtr;
}

template<class T>
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getRightChildPtr()
{
    return rightChildPtr;
}

template<class T>
void LinkedBTreeNode<T>::setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr)
{
    leftChildPtr = newLeftChildPtr;
}

template<class T>
void LinkedBTreeNode<T>::setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr)
{
    rightChildPtr = newRightChildPtr;
}