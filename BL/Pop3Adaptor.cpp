//
//  Pop3Adaptor.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "Pop3Adaptor.h"


const char* Pop3Adaptor::User(const char* userId)//needs to think about the option of getting the fuul adres "username@gmail.com"
{
    _result.assign(userId);
    if (_user->getUserName().compare(_result) == 0)
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    _result.assign("-OK");
    return _result.c_str();
}
const char* Pop3Adaptor::PASS (const char* password)
{
    _result.assign(password);
    if (_user->getPassword().compare(_result))
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    _result.assign("-OK");
    return _result.c_str();
}

const char* Pop3Adaptor::STAT ()
{
    _result.assign("+OK ");
    ostringstream convert;
    convert << userList->getObj(userNum).get_mails().getCount();
    _result += convert.str();
    _result += " ";
    convert.clear();
    convert << sizeof(userList->getObj(userNum).get_mails());
    _result += convert.str();
    return _result.c_str();
}

const char* Pop3Adaptor::LIST()
{
    ostringstream convert;
    _result.assign("+OK ");
    List<MailMessage> mails = userList->getObj(userNum).get_mails();
    convert << mails.getCount();
    _result += convert.str();
    _result += " messages\n";
    for (int i = 0; i < mails.getCount(); ++i)
    {
        convert.clear();
        convert << i;
        _result += convert.str();
        _result += " ";
        convert.clear();
        convert << sizeof(mails.getObj(i));
        _result += convert.str();
        _result += "\n";
    }
    return _result.c_str();
}

const char* Pop3Adaptor::RETR(int msgNumber)
{
    _result.assign(userList->getObj(userNum).get_mails().getObj(msgNumber).getMsg());
    return _result.c_str();
}

const char* Pop3Adaptor::DELE(int msgNumber)
{
    if (msgNumber > userList->getObj(userNum).get_mails().getCount())
        return "-OK";
    userList->getObj(userNum).get_mails().getObj(msgNumber).set_marked_true();
    return "+OK";
}

const char* Pop3Adaptor::RSET()
{
    int i = userList->getObj(userNum).get_mails().getCount();
    for (;i > 0; --i)
    {
        if (!(userList->getObj(userNum).get_mails().getObj(i).getMarked()))
            userList->getObj(userNum).get_mails().getObj(i).set_marked_false();
    }
    return "+OK";
}
const char* Pop3Adaptor::QUIT()
{
    userList->getObj(userNum).deleteMarked();
    return "+OK";
}

