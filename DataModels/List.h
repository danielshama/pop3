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
    ~List();
    
};

#endif /* defined(__pop3__List__) */
