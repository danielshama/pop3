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
#include "DateTime.h"

class MailMessage
{
private:
    int _Id;
    string _from,_to;
    string _data;
    DateTime _mailTime;
public:
    MailMessage(int ID,string from,string to,string data, DateTime mailT);
    const string& getMsg();
    const string& fromWho();
};

#endif /* defined(__pop3__MailMessage__) */
