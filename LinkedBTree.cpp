#include "LinkedBTree.h"

template<class T>
LinkedBTree<T>::LinkedBTree() {}

template<class T>
LinkedBTree<T>::~LinkedBTree()
{
    clear();
}

template<class T>
bool LinkedBTree<T>::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class T>
int LinkedBTree<T>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

template<class T>
int LinkedBTree<T>::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(rootPtr);
}

template<class T>
T LinkedBTree<T>::getRootData() const
{
    if(rootPtr != nullptr)
        return rootPtr->getItem();

    else
    {
        std::string message = "Entry doesn't exist";
        throw(NotFoundExcep(message));
    }
}

template<class T>
void LinkedBTree<T>::preorderTraverse(void visit(T&)) const
{
    preorder(visit, rootPtr);
}

template<class T>
void LinkedBTree<T>::inorderTraverse(void visit(T&)) const
{
    inorder(visit, rootPtr);
}

template<class T>
void LinkedBTree<T>::postorderTraverse(void visit(T&)) const
{
    postorder(visit, rootPtr);
}

template<class T>
int LinkedBTree<T>::getHeightHelper(LinkedBTreeNode<T>* subTreePtr) const
{
   if (subTreePtr == nullptr)
     return 0;

   else
     return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
 }

template<class T>
int LinkedBTree<T>::getNumberOfNodesHelper(LinkedBTreeNode<T>* subTreePtr) const
{
  if(subTreePtr == nullptr)
    return 0;
  
  else
    return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class T>
LinkedBTreeNode<T>* LinkedBTree<T>::copyTree(const LinkedBTreeNode<T>* treePtr) const
{
    LinkedBTreeNode<T>* newTreePtr = nullptr;

    if (treePtr != nullptr )
    {
        newTreePtr = new LinkedBTreeNode<T>(treePtr->getItem(), nullptr, nullptr );
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }
    
    return newTreePtr;
}

template<class T>
void LinkedBTree<T>::clear()
{
    destroyTree(rootPtr);
}

template<class T>
void LinkedBTree<T>::destroyTree(LinkedBTreeNode<T>* treePtr)
{
  if (treePtr != nullptr)
  {
    destroyTree(treePtr->getLeftChildPtr());
    destroyTree(treePtr->getRightChildPtr());
    treePtr->setLeftChildPtr(nullptr);
    treePtr->setRightChildPtr(nullptr);
    delete treePtr;
    treePtr = nullptr;
  }

  rootPtr = nullptr;

}

template<class T>
void LinkedBTree<T>::preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const
{
  if (treePtr != nullptr)
  {
    T theItem = treePtr->getItem();
    visit(theItem);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<class T>
void LinkedBTree<T>::inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    T theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<class T>
void LinkedBTree<T>::postorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const
{
  if (treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    T theItem = treePtr->getItem();
    visit(theItem);
  }
}
