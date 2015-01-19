//
//  Pop3Adaptor.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "Pop3Adaptor.h"


//Pop3Adaptor::Pop3Adaptor(List<User> *user)
//{
//    userList = user;
//}
const char* Pop3Adaptor::User(const char* userId)//needs to think about the option of getting the fuul adres "username@gmail.com"
{
    string temp(userId);
    int num = userList->getCount();
    for (int i = 0; i <= num; ++i)
    {
        if ((userList->getObj(i).getUserName().compare(temp)) == 0)
        {
            userNum = i;
            return "+OK";
        }
    }
    return "-OK";
}
const char* Pop3Adaptor::PASS (const char* password)
{
    string temp(password);
    if ((userList->getObj(userNum).getPassword().compare(temp)) == 0)
    {
        return "+OK";
    }
    return "-OK";
}

const char* Pop3Adaptor::STAT ()
{
    delete res;
    string result = "+OK ";
    ostringstream convert;
    convert << userList->getObj(userNum).get_mails().getCount();
    result += convert.str();
    result += " ";
    convert.clear();
    convert << sizeof(userList->getObj(userNum).get_mails());
    result += convert.str();
    res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    return res;
}

const char* Pop3Adaptor::LIST()
{
    delete res;
    ostringstream convert;
    string result = "+OK ";
    List<MailMessage> mails = userList->getObj(userNum).get_mails();
    convert << mails.getCount();
    result += convert.str();
    result += " messages\n";
    for (int i = 0; i < mails.getCount(); ++i)
    {
        convert.clear();
        convert << i;
        result += convert.str();
        result += " ";
        convert.clear();
        convert << sizeof(mails.getObj(i));
        result += convert.str();
        result += "\n";
    }
    res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    return res;
}

const char* Pop3Adaptor::RETR(int msgNumber)
{
    delete res;
    string result = userList->getObj(userNum).get_mails().getObj(msgNumber).getMsg();
    res = new char[result.length() + 1];
    strcpy(res, result.c_str());
    return res;
}

const char* Pop3Adaptor::DELE(int msgNumber)
{
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

