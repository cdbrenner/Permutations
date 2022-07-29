#pragma once

 template<class T> 
 class TreeInterface
 { 
    public: 
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;
        virtual int getNumberOfNodes() const = 0; 
        virtual T getRootData() const = 0;
        virtual bool add(const T& newEntry) = 0;
        virtual bool remove(const T& anEntry) = 0;
        virtual void clear() = 0; 
        virtual T getEntry(const T& anEntry) const = 0; 
        virtual bool contains(const T& anEntry) const = 0;
 };