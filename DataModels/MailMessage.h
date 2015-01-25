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
    int _Id,_size; //what is size?
    string _from,_to;
    string _data;
    DateTime _mailTime;
    bool marked; // init false, true is for delete in quit
    static int counter;
public:
    MailMessage(int ID,string from,string to,string data, DateTime mailT); // need to calculate the size
    static int getMsgAmount();
    string& getMsg(); //
    bool getMarked(); //
    void set_marked_true(); //
    void set_marked_false(); //
    void operator=(const MailMessage&);//we have to do it for the delete in user's mails list. not shure if we need it because it doesn't have any dynamic memory
    ~MailMessage();
};

#endif /* defined(__pop3__MailMessage__) */
