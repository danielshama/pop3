//
//  MailInterface.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "MailInterface.h"

bool MailInterface::Authenticate(string userName, string passWord){
    bool answer = _resultSupp.AuthenticateUser(userName, passWord);
    return answer;
}

//check it again