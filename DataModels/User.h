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
    string const _userName, _passWord;
    int if_Open, userId;
    static int Count;
    List<MailMessage> msgsList;
public:
    User();
    User(string, string, int =0);
    User(const User& other);
    void setUser(string name, string password);
    void setUserName(string);
    void setMsgList(List<MailMessage>);
    void setPassword(string);
    string getUserName();
    string getPassword();
    ~User();
};
bool operator==(const User& user1, const User& user2);

#endif /* defined(__pop3__User__) */
