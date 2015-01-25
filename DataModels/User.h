//
//  User.h
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__User__
#define __pop3__User__

#include "Includes.h"
#include "List.h"
#include "MailMessage.h"


class User
{
private:
    string _userName, _passWord;//not able to work with const
    int if_Open;//probably we don't need it
    int userId;
    static int Count;
    List<MailMessage> *msgsList;
public:
    User(string name, string pass, int _id) {_userName = name; _passWord = pass; userId = _id;}
    User(const User&);            //
    void setUser(string, string); //
    void setUserName(string);     //
    void setMsgList(List<MailMessage> *);//
    void setPassword(string);     //
    int const get_userID();       //
    string const getUserName();   //
    string const getPassword();   //
    List<MailMessage>& get_mails();//
    void deleteMarked();
    ~User();
};
bool operator==(const User& user1, const User& user2);



#endif /* defined(__pop3__User__) */
