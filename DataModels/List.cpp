//
//  List.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama & Or Ben David. All rights reserved.
//

#include "List.h"

template <class T>
List<T>::List(): count(0)
{
    array = new T[N];
}


template <class T>
void List<T>::add(T newObj)
{
    if(count % N == 0 && count != 0){
        T newArr = new T[count+N];
        for(int i=0 ; i<count ; i++){
            newArr[i]=array[i];
        }
        delete[] array;
        array = newArr;
    }else array[count] = newObj;
    
    count++;
}

template <class T>
List<T>::~List()
{
    delete[] array;
}