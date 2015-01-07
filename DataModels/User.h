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

class User
{
private:
    string const _userName, _passWord;
    int if_Open;
public:
    User(string, string, int =0);
    User(User& other);
    string getUserName();
    string getPassword();
    ~User();
};
bool operator==(const User& user1, const User& user2);

#endif /* defined(__pop3__User__) */
