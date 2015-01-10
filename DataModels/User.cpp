//
//  User.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/7/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "User.h"

List<MailMessage> *User::get_mails()
{
    return mails;
}