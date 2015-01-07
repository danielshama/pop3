//
//  MailMessage.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__MailMessage__
#define __pop3__MailMessage__

#include "Includes.h"
#include "DataTime.h"

class MailMessage
{
private:
    int Id,size;
    string from, to, data;
    DataTime mailTime;
    
public:
    MailMessage();
    ~MailMessage();
};

#endif /* defined(__pop3__MailMessage__) */
