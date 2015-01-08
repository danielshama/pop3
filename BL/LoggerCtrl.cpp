//
//  LoggerCtrl.cpp
//  PoP3
//
//  Created by Or Ben David on 1/8/15.
//  Copyright (c) 2015 Or Ben David. All rights reserved.
//

#include "LoggerCtrl.h"

LoggerCtrl::LoggerCtrl()
{
    logger.open("logger.txt", ios::app);
}

void LoggerCtrl::add_to_logger(string line)
{
    logger << line << endl;
}
