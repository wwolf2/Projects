/*
 * dll.h
 * Implementation of double Link List class
 * Author: Billy Wolf
 * Created: May 5, 2019
 * Current: May 8, 2019
 */

#ifndef DLL_H
#define DLL_H
#include <iostream>
#include "dll_node.h"
using namespace std;
template <typename T>
class list{

public: //functions
    
    void Insert(T newValue);
    void Remove(int numToRemove);
    void DisplayList();
    bool FindStudent(string );
    int SizeNode();
    void Sort();
    dnode<T> *head = nullptr;


};


template <typename T>
void list<T>::Insert(T newValue){ //insert node at begining
    dnode<T> *newNode;
    
    newNode = new dnode<T>;
    newNode->value = newValue;
    
    if(head != nullptr)
        head->previousNode = newNode;
    
    newNode-> previousNode = nullptr;
    newNode-> nextNode = head;
    
    head = newNode;
        
}
template <typename T>
void list<T>::Remove(int numToRemove){ //remove node number
    int count = 1;
    dnode<T> * nodePtr;
    dnode<T> * prev;
    dnode<T> * next;

    if (!head){
    cout << "Empty list, unable to delete " << endl;
    return;
    }
    
    if (numToRemove == 1){
    nodePtr = head->nextNode;
    delete head;
    head = nodePtr;
    cout << "Removed student 1" <<endl;
    }
    
    nodePtr = head;
    
    while(nodePtr != nullptr){
          nodePtr = nodePtr->nextNode;
            count ++;
        if (count == numToRemove){
        prev = nodePtr->previousNode;
        next = nodePtr->nextNode;
        delete nodePtr;
        prev->nextNode = next;
        if (next != nullptr)
            next->previousNode = prev;
        cout << "Removed student " << count << endl;
        break;
            
        }
        
     }
     
}   


template <typename T>
void list<T>::DisplayList() { //Displays the list
    
    dnode<T> *nodePtr;
    int count = 1;
    nodePtr = head;
    if (!head){
    cout << "Empty list, nothing to display " << endl;
    return;
         
    }
    cout << "There are " << SizeNode();
    cout << " students in the database" <<endl;
     while(nodePtr){
        
     cout << count << ". " << nodePtr->value << endl;
     
     nodePtr = nodePtr->nextNode;
     count++;
    }
}

template <typename T>
int list<T>::SizeNode(){ //returns the size of the database
 
    dnode<T> *nodePtr;
    int count = 0;
    nodePtr = head;
    while (nodePtr != nullptr){
     nodePtr = nodePtr->nextNode;
     count = count + 1;
    }
    return count;
}


template <typename T>
bool list<T>::FindStudent(string findName){ //Finds a student and returns a bool
    
    dnode<T> * nodePtr;
    nodePtr = head;
    
    while (nodePtr != nullptr){
     
        if(nodePtr->value.name == findName){
            cout << "The student is found in the database" << endl;
          return true;  
        }
        nodePtr=nodePtr->nextNode;
    }
    cout << "The student is not found in the database" << endl;
    return false;
    
    
}


template <typename T>
void list<T>::Sort(){ //sorts the database
    
    dnode<T> * nodePtr;
    int swap = 0;
    bool end;
    int count;
    T temp;
    
     if (!head){
    cout << "Empty list, nothing to sort " << endl;
    return;
     }
    if (SizeNode() == 1){
        cout << "Only 1 student, nothing to sort " << endl;
    return;
    }
    
    do{
        swap = 0;
         nodePtr = head;
      
     while (nodePtr != nullptr && nodePtr->nextNode != nullptr){ 
        
         if (nodePtr->value.name > nodePtr->nextNode->value.name){
         temp = nodePtr->value;
         nodePtr->value = nodePtr->nextNode->value;
         nodePtr->nextNode->value = temp;
         swap ++;
        }
        nodePtr = nodePtr->nextNode;
}
        //end = true;
        
        }while (swap > 0);
    cout << "The database is sorted alphabetically by name" << endl;
}
#endif
