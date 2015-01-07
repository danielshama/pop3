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

class MailInterface
{
private:
    
public:
    MailInterface();
    
    bool Authenticate(string user, string password);
    
    void GetMailStatus();
    
    void GetMailList();
    
    void GetOneMail(int mailNum);
    
    void DeleteMail(int mailNum);
    
    void RSET();
    
    void Quit(){ exit(0);}
    
    ~MailInterface();
};

#endif /* defined(__pop3__MailInterface__) */
