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
#define N 5

template <class T>
class List
{
private:
    
    T *array;
    int count;
    
public:
    
    List();
    void add(T);
    T& getObj(int);
    void deleteObj();
    void del(T);
    int getCount();
    T& operator[](int i); // update
    T& operator[](int i) const;//
    ~List();
    
};


template <class T>
List<T>::List(): count(0)
{
    array = new T[N];
}


template <class T>
void List<T>::add(T newObj)
{
    if(count % N == 0 && count != 0){
        T *newArr = new T[count+N];
        for(int i=0 ; i<count ; i++){
            newArr[i]=array[i];
        }
        delete[] array;
        array = newArr;
        delete[] newArr;
    }
    array[count] = newObj;
    count++;
}

template <class T>
T& List<T>::getObj(int objNum){
    return array[objNum];
}

template <class T>
List<T>::~List()
{
    delete[] array;
}
#endif /* defined(__pop3__List__) */
