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
#include "emailAddress.h"
#include "DateTime.h"

class MailMessage
{
private:
    int Id,size;
    EmailAddress from,to;
    string data;
    DataTime mailTime;
    bool marked; // init false, true is for delete in quit
    static int counter;
public:
    MailMessage();
    static int getMsgAmount();
    ~MailMessage();
};

#endif /* defined(__pop3__MailMessage__) */
