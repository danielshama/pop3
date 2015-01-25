//
//  MailMessage.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama  & Or Ben David. All rights reserved.
//

#include "MailMessage.h"

MailMessage::MailMessage(int ID, string from, string to, string data, DateTime mailT)
{
    _Id = ID;
    _from.assign(from);
    _to.assign(to);
    _data.assign(data);
    marked = false;
    counter += 1;
}

void MailMessage::operator=(const MailMessage& mail)
{
    _Id = mail._Id;
    _from.assign(mail._from);
    _to.assign(mail._to);
    _data.assign(mail._data);
    marked = mail.marked;
}

string& MailMessage::getMsg()
{
    return _data;
}

void MailMessage::set_marked_true()
{
    marked = true;
}

void MailMessage::set_marked_false()
{
    marked = false;
}

bool MailMessage::getMarked()
{
    return marked;
}

MailMessage::~MailMessage()
{
    counter -= 1;
}
