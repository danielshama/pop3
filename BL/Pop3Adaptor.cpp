//
//  Pop3Adaptor.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "Pop3Adaptor.h"


const char* Pop3Adaptor::User(const string userId)
{
    _result.assign(userId);
    if(userId.find("@") == string::npos){
        string usert = _user->getUserName();
        int loc =(int)usert.find("@");
        usert.erase(loc);
        if(usert.compare(_result) == 0){
            _result.assign("+OK");
            return _result.c_str();
        }
    }
    _result.assign(userId);
    if (_user->getUserName().compare(_result) == 0)
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    _result.assign("-OK");
    return _result.c_str();
}
const char* Pop3Adaptor::PASS (const string password)
{
    _result.assign(password);
    if (_user->getPassword().compare(_result)==0)
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    _result.assign("-OK");
    return _result.c_str();
}

const char* Pop3Adaptor::STAT ()
{
    //_user->get_mails()->prinall();
    int mailBoxSize =_user->get_mails()->getAmount();
    _result.assign("+OK ");
    _result += to_string(mailBoxSize);
    _result += " ";
    long long int _size = 0;
    for (int i = 1; i <= mailBoxSize; ++i)
    {
        _size += sizeof(_user->get_mails()->getObj(i));
    }
    _result += to_string(_size);
    return _result.c_str();
}

const char* Pop3Adaptor::LIST()
{
    _result.assign("+OK ");
    _result += to_string(_user->get_mails()->getAmount());
    _result += " messages \n";
    if (_user->get_mails()->empty())
        return _result.c_str();
    for (int i = 1; i <= _user->get_mails()->getAmount(); ++i)
    {
        _result += to_string(i);
        _result += " ";
        _result += to_string(sizeof(_user->get_mails()->getObj(i)));
        _result += "\n";
    }
    return _result.c_str();
}

const char* Pop3Adaptor::RETR(int msgNumber)
{
    int x=_user->get_mails()->getAmount();
    if (msgNumber > x)
    {
        _result.assign("-OK");
        return _result.c_str();
    }
    _result.assign("+OK \n\nFrom: ");
    _result += _user->get_mails()->getObj(msgNumber).fromWho();
    _result += "       " + _user->get_mails()->getObj(msgNumber).getMsgTime();
    _result += "\nText: \n  ";
    _result += _user->get_mails()->getObj(msgNumber).getMsg();
    _result += "\n";
    return _result.c_str();
}

const char* Pop3Adaptor::DELE(int msgNumber)
{
    int x=_user->get_mails()->getAmount() ;
    if (x< msgNumber || msgNumber <=0)
    {
        _result.assign("-OK");
        return _result.c_str();
    }
    _user->get_mails()->markForRemove(msgNumber);
    _result.assign("+OK");
    return _result.c_str();
}

const char* Pop3Adaptor::RSET()
{
    int n =_user->get_mails()->getAmount();
    if (_user->get_mails()->empty())
    {
        _result.assign("+OK");
        return _result.c_str();
    }
    for (int i = 1; i <= n; ++i)
    {
        _user->get_mails()->clearMarks(i);
    }
    _result.assign("+OK");
    return _result.c_str();
}

const char* Pop3Adaptor::QUIT()
{
    _dataRe->upDateData();
    _user->get_mails()->remove();
    _result.assign("+OK");
    return _result.c_str();
}

const char* Pop3Adaptor::displaySum()
{
    if (_user->get_mails()->empty())
    {
        _result.assign("empty");
        return _result.c_str();
    }
    _result.assign("");
    int n=_user->get_mails()->getAmount();
    for (int i = 1; i <=n ; ++i)
         {
             _result += to_string(i);
             _result += ") from: " + _user->get_mails()->getObj(i).fromWho();
             _result += "  text: ";
             _result += _user->get_mails()->getObj(i).getMsg().substr(0,5);
             _result += "... ";
             if(_user->get_mails()->ifForDel(i)){
                 _result += "(Marked for delete).";
             }
             _result += "\n";
         }
    return _result.c_str();
}
