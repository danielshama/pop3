//
//  mail_container.cpp
//  PoP3
//
//  Created by Or Ben David on 1/7/15.
//  Copyright (c) 2015 Or Ben David. All rights reserved.
//

#include "mail_container.h"

template <class T>
Container<T>::Container()
{
    mails = new T [N];
    return;
}

template <class T>
Container<T>::~Container()
{
    delete T;
}

template <class T>
void Container<T>::add(T)
{
    
}