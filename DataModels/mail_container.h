//
//  mail_container.h
//  PoP3
//
//  Created by Or Ben David on 1/7/15.
//  Copyright (c) 2015 Or Ben David. All rights reserved.
//

#ifndef __PoP3__mail_container__
#define __PoP3__mail_container__

#include "Includes.h"
#include "MailMessage.h"
#define N 50
template <class T>
class Container
{
private:
    
    T *mails;
    int count = 0;
    
public:
    
    Container();
    ~Container();
    void add(T);
    void del(T);
    int get_count();
    
    
};

#endif /* defined(__PoP3__mail_container__) */
