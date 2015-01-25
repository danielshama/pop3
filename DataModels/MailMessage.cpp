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
}

const string& MailMessage::getMsg()
{
    return _data;
}


