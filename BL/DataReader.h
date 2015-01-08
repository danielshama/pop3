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
    string dataAddres;
    List<MailMessage> msgList;
    List<User> userList;
    
    void readFromData(List<MailMessage>&, List<User>&);
public:
    DataReader(string);
    List<User>& getUsers(){ return userList;}
    List<MailMessage>& getMailBox(){ return msgList; }
};

#endif /* defined(__pop3__DataReader__) */
