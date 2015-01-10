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
    void setTime(int _day,int _mounth, int _year, int _hour, int _min, int _sec);
    ~DateTime();
    
};


#endif /* defined(__pop3__DataTime__) */
