//
//  emailAddress.h
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__emailAddress__
#define __pop3__emailAddress__


//why we need that for?, there is alredy a class of user (which holds the user name and password), so you can compare it to that
#include "Includes.h"
class EmailAddress
{
private:
    string _address;
public:
    EmailAddress();
    bool AuthenticateAddress(string addres);
};

#endif /* defined(__pop3__emailAddress__) */
