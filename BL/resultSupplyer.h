//
//  resultSupplyer.h
//  pop3
//
//  Created by Daniel Shamama on 1/10/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__resultSupplyer__
#define __pop3__resultSupplyer__

#include "Includes.h"
#include "DataReader.h"
#include "Pop3Adaptor.h"

class ResultSupplyer{
private:
    DataReader _data;
    
public:
    bool AuthenticateUser(string name, string password);
};

#endif /* defined(__pop3__resultSupplyer__) */
