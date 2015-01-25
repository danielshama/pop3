//
//  MailInterface.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__MailInterface__
#define __pop3__MailInterface__

#include "Includes.h"
#include "MailMessage.h"
#include "User.h"
#include "Pop3Adaptor.h"
#include "List.h"
#include <fstream>

class MailInterface
{
private:
    Pop3Adaptor _pop3;
    int steps;
    bool login;
    
    int printMenu(int);
    void makeAstep(int);
public:
    //MailInterface();
    MailInterface(User);
    
    void runInterFace(); // beginning the interface structer - print choices
    
    bool Authenticate(const char* userName, const char* passWord); // Authenticates the user name and password from the txt file
    
    void GetMailStatus(); // +ok, mail amount, total byte amount
    
    void GetMailList(); //print mails list
    
    void GetOneMail();// print one mail
    
    void DeleteMail(); // marked msg to true by id
    
    void RSET( ); // reset all marked to false
    
    void Quit(); // delete all marked msg and end of running
    
    ~MailInterface();
};

#endif /* defined(__pop3__MailInterface__) */
