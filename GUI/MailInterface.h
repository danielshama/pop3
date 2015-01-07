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

class MailInterface
{
private:
    string dataFileAddres;
    
public:
    MailInterface();
    MailInterface(string dataFile);
    
    void runInterFace(); // beginning the interface structer - print choices
    
    bool Authenticate(); //Authenticates the user name and password from the txt file
    
    void GetMailStatus(); //(not sure) print username, mails amount
    
    void GetMailList(); //print mails list
    
    void GetOneMail(const int mailID);// print one mail
    
    void DeleteMail(const int mainID); // delete one mail by id
    
    void RSET(); // delete all and construct new one
    
    void Quit(){ exit(0);} // end of running
    
    ~MailInterface();
};

#endif /* defined(__pop3__MailInterface__) */
