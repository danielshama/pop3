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
protected:
    
public:
    bool forRemove;
    Node * next;            //pointer to the next node
    Node * prev;            //pointer to the prev node
    T data;                 //placeholder for generic data
    static int count;
    Node(T d);          //constructor
    int getAmount() const;
    T& getDataObj();
    bool ifForRemove();
    void markForRemove();
    void clearMarks();
};

template <class T>
int Node<T>::count =0;

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
    return data;
}
template <class T>
bool Node<T>::ifForRemove(){
    return forRemove;
}
template <class T>
void Node<T>::markForRemove(){
    forRemove = true;
}
template <class T>
void Node<T>::clearMarks(){
    forRemove=false;
}
#endif /* defined(__pop3__Node__) */
