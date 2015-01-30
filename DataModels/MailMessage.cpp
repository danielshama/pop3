//
//  MailMessage.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama  & Or Ben David. All rights reserved.
//

#include "MailMessage.h"

MailMessage::MailMessage(int ID, string from, string to, string data, DateTime& mailT)
{
    _Id = ID;
    _from = from;
    _to = to;
    _data= data;
    _mailTime = mailT;
}
MailMessage::MailMessage(const MailMessage& o){
    _Id = o._Id;
    _from = o._from;
    _to = o._to;
    _data = o._data;
    _mailTime = o._mailTime;
}
const string& MailMessage::getMsg()
{
    return _data;
}
int MailMessage::getId(){
    return _Id;
}
const string MailMessage::getMsgTime(){
    return _mailTime.get_time();
}

const string& MailMessage::fromWho(){
    return _from;
}

