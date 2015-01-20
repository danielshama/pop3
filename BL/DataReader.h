//
//  DataReader.h
//  pop3
//
//  Created by Daniel Shamama on 1/8/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__DataReader__
#define __pop3__DataReader__

#include "Includes.h"
#include "MailMessage.h"
#include "User.h"
#include "List.h"

class DataReader{
private:
    const char** dataAddres;
    //List<MailMessage> *Msgs;
    List<User> *_users;
    
    void readFromData(int);
    DateTime calculDateTime(string);
public:
    DataReader(const char**,int); //update
    User& getUser(int userID);
    List<User> *getUserList();
    List<MailMessage> *getMailBox(int);
};

#endif /* defined(__pop3__DataReader__) */
