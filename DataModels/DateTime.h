//
//  DataTime.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

/*explenation:
 holds all the data of the the time, which belongs to a massage.
 on the "outside" it presents the time as one long string which build up from all the variables in the private section*/

#ifndef __pop3__DataTime__
#define __pop3__DataTime__

#include <iostream>
#include "includes.h"


class DateTime{
private:
    
    int day,month,year,hour,minute,second;
    
public:
    DateTime();
    DateTime(const DateTime& other);
    void get_time();
    void setDay(int d){day = d;}
    void setMonth(int m){month =m;}
    void setYear(int y){ year=y;}
    void setHour(int h){hour=h;}
    void setMinute(int m){minute=m;}
    void setSecond(int s){second=s;}
    void setTime(int, int, int, int , int, int);
    DateTime& operator=(const DateTime&);
    
    DateTime(int, int, int, int, int, int);
    ~DateTime();
};


#endif /* defined(__pop3__DataTime__) */
