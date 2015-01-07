//
//  DataTime.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__DataTime__
#define __pop3__DataTime__

#include <stdio.h>

class DataTime{
private:
    int day,month,year,hour,minute,second;
public:
    DataTime();
    ~DataTime();
    void get_time();
};


#endif /* defined(__pop3__DataTime__) */
