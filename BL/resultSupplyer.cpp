//
//  resultSupplyer.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/10/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "resultSupplyer.h"
#include "User.h"


bool ResultSupplyer::AuthenticateUser(string name, string password){
    User _user = _data.getUser();
    
    if(_user.getUserName() == name)
        if(_user.getPassword() == password)
            return true;
    
    return false;
}