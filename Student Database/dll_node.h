/*
 * dll_node.h
 * Implementation of double LL node class
 * Author: Billy Wolf
 * Created: May 5, 2019
 * Current: April 8, 2019
 */

#ifndef DLL_NODE_H
#define DLL_NODE_H

#include "student.h"
#include <iostream>

using namespace std;

template <typename T>
class dnode {

public: //node class
    T value;
    dnode *nextNode;
    dnode *previousNode;
    dnode(); 
    dnode(T, dnode *, dnode *);
};

template <typename T>
dnode<T>::dnode(){ //constuctor for node
    nextNode = nullptr;
    previousNode = nullptr;
}
template <typename T>
dnode<T>::dnode(T val, dnode *next, dnode *prev){ //non defualt constuctor for node
    
 value = val;
 nextNode = next;
 previousNode = prev;
 
}


#endif