
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright 2015 Daniel Shamama. All rights reserved.
//

#include "Includes.h"
#include "DataReader.h"
#include "MailInterface.h"

int main(int argc, const char * argv[]) {
    DataReader _dataReader(argv[0]);
    MailInterface _mailInterFace(_dataReader.getUserList());
    
    return 0;
}
