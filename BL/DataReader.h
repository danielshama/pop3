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
    List<MailMessage> Msgs;
    User _user;
    
    void readFromData();
    DateTime calculDateTime(string);
public:
    DataReader(string);
    User& getUsers(){ return _user;}
    List<MailMessage>& getMailBox(){ return Msgs; }
};

#endif /* defined(__pop3__DataReader__) */
