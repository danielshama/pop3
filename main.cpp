
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright 2015 Daniel Shamama. All rights reserved.
//

#include "Includes.h"
#include "DataReader.h"
#include "MailInterface.h"

int main(int argc, const char * argv[]) {
    string s="Example.txt";
//    DataReader _dataReader(s.c_str());
//    _dataReader.readFromData();
    MailInterface _mailInterFace(argv[1]);
    _mailInterFace.runInterFace();
    return 0;
}
