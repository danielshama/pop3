//
//  List.h
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama & Or Ben David. All rights reserved.
//

#ifndef __pop3__List__
#define __pop3__List__

#include "Includes.h"
#include "Node.h"


//a circular doubly-linked list
template <class T>
class List
{
private:
    Node<T> *p;        //reference to the current node
    Node<T> *head;
public:
    
    List();               //constructor
    bool empty();               //returns true if the list is empty, false otherwise
    int getAmount();                 //returns the number of elements in the list
    void insert(T& d); //inserts a node before the current node
    void clearMarks(int);
    void markForRemove(int);
    T& getObj(int);             //returns the data of the node
    void remove();              //remove items that marked
    ~List();
    void prinall();
};



template <class T>
List<T>::List(): p(NULL), head(NULL)
{
    
}
template <class T>
List<T>::~List()
{
    cout << "!!!!! " << endl;
}

template <class T>
void List<T>::prinall()
{
    Node<T> *t = head;
    int count=0;
    
    while(t != NULL){
        cout << count << ", ";
        t = t->next;
        count++;
    }
    cout << endl;
}


template <class T>
bool List<T>::empty()
{
    if (p == NULL) return true;
    else return false;
}

template <class T>
int List<T>::getAmount()
{
    return p->getAmount();
}

template <class T>
void List<T>::insert(T& newD)
{
    if (p == NULL)
    {
        p = new Node<T>(newD);
        if(p == NULL) {
            cout << " eror new node fs" << endl;
            return;
        }
        head=p;
        p->next = NULL;
        p->prev = NULL;
    }
    else
    {
        p->next = new Node<T>(newD);
        if(p->next != NULL){
            p->next->prev = p;
            p = p->next;
            p->next = NULL;
        }else cout << " eror new node"<< endl;
    }
}


template <class T>
T& List<T>::getObj(int objId)
{
    Node<T> *t = head;
    int count=0;
    
    while(t != NULL){
        if(count== objId)
            return t->getDataObj();
        t = t->next;
        count++;
    }
    return head->getDataObj();
}

template <class T>
void List<T>::markForRemove(int objId){
    Node<T> *t = head;
    int count=0;
    
    while(t != NULL){
        if(count== objId){
            t->markForRemove();
            return;
        }
        t = t->next;
        count++;
    }
}

template <class T>
void List<T>::remove()
{
    Node<T> *t =head, *s=t;
    while(t!=NULL){
        if(t->ifForRemove()){
            if(t==head){
                head = t->next;
                t->~Node();
                s = t = head;
            }else{
                s->next = t->next;
                t->~Node();
                t=s->next;
                t=t->next;
            }
        }
        t=t->next;
    }
}

template <class T>
void List<T>::clearMarks(int objId){
    Node<T> *t = head;
    int count=0;
    while(t != NULL){
        if(count == objId){
            t->clearMarks();
            return;
        }
        t = t->next;
        count++;
    }
}



#endif /* defined(__pop3__List__) */
