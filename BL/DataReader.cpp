//
//  DataReader.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/8/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "DataReader.h"
#include <fstream>


DataReader::DataReader(string dataFile): dataAddres(dataFile){
    readFromData(msgList,userList);
}

void readFromData(List<MailMessage>&, List<User>&){
    
}
