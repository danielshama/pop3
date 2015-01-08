//
//  LoggerCtrl.h
//  PoP3
//
//  Created by Or Ben David on 1/8/15.
//  Copyright (c) 2015 Or Ben David. All rights reserved.
//

#ifndef __PoP3__LoggerCtrl__
#define __PoP3__LoggerCtrl__

#include <iostream>
#include <fstream>

using namespace std;

class LoggerCtrl
{
    
private:
    
    ofstream logger;
    
public:
    LoggerCtrl();
    
    void add_to_logger(string);
    
    
};

#endif /* defined(__PoP3__LoggerCtrl__) */
