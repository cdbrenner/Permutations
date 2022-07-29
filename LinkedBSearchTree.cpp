#include "LinkedBSearchTree.h"

template<class T>
LinkedBSearchTree<T>::LinkedBSearchTree() {}

template<class T>
LinkedBSearchTree<T>::LinkedBSearchTree(const T& item)
{
    LinkedBTree<T>::rootPtr = new LinkedBTreeNode<T>(item);
}

template<class T>
LinkedBSearchTree<T>::~LinkedBSearchTree()
{
    LinkedBTree<T>::clear();
}

template<class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessful)
{
    if (subTreePtr == nullptr)
        isSuccessful = false;
    
    else if(subTreePtr->getItem() == target)
    {
        isSuccessful = true;
        return removeNode(subTreePtr);
    }

    else if(subTreePtr->getItem() > target)
    {
        LinkedBTreeNode<T>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    } 

    else
    {
        LinkedBTreeNode<T>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    } 

    return subTreePtr;
}

template<class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeNode(LinkedBTreeNode<T>* nodePtr)
{
    if(nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }

    else if((nodePtr->getLeftChildPtr() != nullptr && nodePtr->getRightChildPtr() == nullptr)
            || (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr))
    {
        LinkedBTreeNode<T>* nodeToConnectPtr;

        if(nodePtr->getLeftChildPtr() != nullptr)
            nodeToConnectPtr = nodePtr->getLeftChildPtr();

        else
            nodeToConnectPtr = nodePtr->getRightChildPtr();

        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }

    else
    {
        T newNodeValue;

        LinkedBTreeNode<T>* temp = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(temp);
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }

}

template<class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::removeLeftmostNode(LinkedBTreeNode<T>* nodePtr, T& inorderSuccessor)
{
    if(nodePtr->getLeftChildPtr() == nullptr)
    {
        inorderSuccessor = nodePtr->getItem();

        return removeNode(nodePtr);
    }

    else
    {
        LinkedBTreeNode<T>* temp = removeLeftmostNode(nodePtr->getLeftChildPtr(),inorderSuccessor);
        nodePtr->setLeftChildPtr(temp);
        return nodePtr;
    }
}

template<class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::findNode(LinkedBTreeNode<T>* treePtr, const T& target) const
{

    if(treePtr == nullptr)
        return nullptr;

    else if(treePtr->getItem() == target)
        return treePtr;

    else if(treePtr->getItem() > target)
        return findNode(treePtr->getLeftChildPtr(),target);

    else
        return findNode(treePtr->getRightChildPtr(),target);
}

template<class T>
bool LinkedBSearchTree<T>::add(const T& newData)
{
    LinkedBTreeNode<T>* newNodePtr = new LinkedBTreeNode<T>(newData);
    LinkedBTree<T>::rootPtr = placeNode(LinkedBTree<T>::rootPtr,newNodePtr);
    return true;
}

template<class T>
LinkedBTreeNode<T>* LinkedBSearchTree<T>::placeNode(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr)
{
    if(subTreePtr == nullptr)
        return newNodePtr;

    else if(subTreePtr->getItem() > newNodePtr->getItem())
    {
        LinkedBTreeNode<T>* temp = placeNode(subTreePtr->getLeftChildPtr(),newNodePtr);
        subTreePtr->setLeftChildPtr(temp);
    }

    else
    {
        LinkedBTreeNode<T>* temp = placeNode(subTreePtr->getRightChildPtr(),newNodePtr);
        subTreePtr->setRightChildPtr(temp);
    }

    return subTreePtr;
}

template<class T>
bool LinkedBSearchTree<T>::remove(const T& target) 
{
    bool success = false;
    LinkedBTree<T>::rootPtr = removeValue(LinkedBTree<T>::rootPtr, target, success);
    return success;
}

template<class T>
T LinkedBSearchTree<T>::getEntry(const T& anEntry) const
{

    LinkedBTreeNode<T>* item = findNode(LinkedBTree<T>::rootPtr, anEntry);

    if(item != nullptr)
        return item->getItem();

    else
    {
        std::string message = "Entry doesn't exist";
        throw(NotFoundExcep(message));
    }

}

template<class T>
bool LinkedBSearchTree<T>::contains(const T& anEntry) const
{
    LinkedBTreeNode<T>* result = findNode(LinkedBTree<T>::rootPtr, anEntry);
    return result != nullptr;
}
