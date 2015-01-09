//
//  DataTime.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__DataTime__
#define __pop3__DataTime__

#include <iostream>
#include <string>

using namespace std;

class DataTime{
    
private:
    
    int day,month,year,hour,minute,second;
    
public:
    
    DataTime(int, int, int, int, int, int);
    
    DataTime();
    
    ~DataTime();
    
    string *get_time();
};


#endif /* defined(__pop3__DataTime__) */
