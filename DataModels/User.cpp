//
//  User.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "User.h"

User::User(const User& other)//what to do with the id
{
    _userName.assign(other._userName);
    _passWord.assign(other._passWord);
    ++Count;
}

int const User::get_userID()
{
    return userId;
}

string const User::getUserName()
{
    return _userName;
}

string const User::getPassword()
{
    return _passWord;
}

List<MailMessage>& User::get_mails()
{
    return *msgsList;
}

void User::setUserName(string name)
{
    _userName.assign(name);
}

void User::setPassword(string pass)
{
    _passWord.assign(pass);
}

void User::setUser(string name, string pass)
{
    _userName.assign(name);
    _passWord.assign(pass);
}

void User::setMsgList(List<MailMessage> *list)
{
    msgsList = list;
}

//void User::deleteMarked()//don't know how to do that!!!
//{
//    int counter = 0;
//    int i = msgsList->getCount();
//    for (; i > 0; --i)
//    {
//        if (msgsList->getObj(i).getMarked())
//            ++counter;
//    }
//    if (counter > 0)
//    {
//        List<MailMessage> *newList = new List<MailMessage>[msgsList->getCount() - counter];
//        for (int j = 0; j < msgsList->getCount() - counter; ++j)
//        {
//            
//        }
//    }
//}
