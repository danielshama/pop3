//
//  Node.h
//  pop3
//
//  Created by Daniel Shamama on 1/25/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__Node__
#define __pop3__Node__

#include <stdio.h>
//node
template <class T>
class Node
{
private:
    bool forRemove;
    Node * next;            //pointer to the next node
    Node * prev;            //pointer to the prev node
    T data;                 //placeholder for generic data
    static int count;
public:    
    Node(T d);          //constructor
    int getAmount() const;
    T& getDataObj();
    int getObjId();
    bool ifForRemove();
    void markForRemove();
    void clearMarks();
    void print();
    ~Node();
};

template <class T>
Node<T>::Node(T d): next(NULL),prev(NULL),data(d),forRemove(false)
{
    count++;
}

template <class T>
int Node<T>::getAmount() const
{
    return count;
}

template <class T>
T& Node<T>::getDataObj(){
    
}
template <class T>
int Node<T>::getObjId(){
    
}
template <class T>
bool Node<T>::ifForRemove(){
    
}
template <class T>
void Node<T>::markForRemove(){
    
}
template <class T>
void Node<T>::clearMarks(){
    
}
template <class T>
void Node<T>::print(){
    
}
#endif /* defined(__pop3__Node__) */
