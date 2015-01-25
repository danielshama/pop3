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
    convert << _user->get_mails().getAmount();
    _result += convert.str();
    _result += " ";
    convert.clear();
    long long int _size = 0;
    for (int i = 1; i <= _user->get_mails().getAmount(); ++i)
    {
        _size = sizeof(_user->get_mails().getObj(i));
    }
    convert << _size;
    _result += convert.str();
    return _result.c_str();
}

const char* Pop3Adaptor::LIST()
{
    ostringstream convert;
    _result.assign("+OK ");
    convert << _user->get_mails().getAmount();
    _result += convert.str();
    _result += " messages\n";
    if (_user->get_mails().empty())
        return _result.c_str();
    for (int i = 1; i <= _user->get_mails().getAmount(); ++i)
    {
        convert.clear();
        convert << i;
        _result += convert.str();
        _result += " ";
        convert.clear();
        long long _size = sizeof(_user->get_mails().getObj(i));
        convert << _size;
        _result += convert.str();
        _result += "\n";
    }
    return _result.c_str();
}

const char* Pop3Adaptor::RETR(int msgNumber)
{
    _result.assign(_user->get_mails().getObj(msgNumber).getMsg());
    return _result.c_str();
}

const char* Pop3Adaptor::DELE(int msgNumber)
{
    if (_user->get_mails().getAmount() < msgNumber)
    {
        _result.assign("-OK");
        return _result.c_str();
    }
    _user->get_mails().markForRemove(msgNumber);
    _result.assign("+OK");
    return _result.c_str();
}

const char* Pop3Adaptor::RSET()
{
    if (_user->get_mails().empty())
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    for (int i = 1; i <= _user->get_mails().getAmount(); ++i)
    {
        _user->get_mails().clearMarks(i);
    }
    _result.assign("+OK");
    return _result.c_str();
}

const char* Pop3Adaptor::QUIT()
{
    _user->get_mails().remove();
    _result.assign("+OK");
    return _result.c_str();
}
