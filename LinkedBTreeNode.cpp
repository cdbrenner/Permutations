#include "LinkedBTreeNode.h"

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode() {}

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData)
    : item(newData) {}

template<class T>
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right)
    : item(newData), leftChildPtr(left), rightChildPtr(right) {}

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