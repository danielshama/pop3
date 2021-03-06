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

//reads all the data from the "example.txt" file and puts it into the variables/classes

class DataReader{
private:
    const string dataAddres;
    User _user;
    
    DateTime calculDateTime(string);
public:
    void readFromData();
    DataReader(const char*); //update
    DataReader(const DataReader&);
    void upDateData();
    User* getUser();
    List<MailMessage> *getMailBox(int);
};

#endif /* defined(__pop3__DataReader__) */
