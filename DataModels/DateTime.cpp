//
//  DataTime.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "DateTime.h"

DateTime::DateTime()
{
    day = month = year = hour = minute = second = 0;
}

DateTime::DateTime(int yr, int mn, int dy, int hr, int mt, int sc)
{
    year = yr;
    month = mn;
    day = dy;
    hour = hr;
    minute = mt;
    second = sc;
}
DateTime::DateTime(const DateTime& other){
    year = other.year;
    month = other.month;
    day = other.day;
    hour = other.hour;
    minute = other.minute;
    second = other.second;
}

void DateTime::setTime(int _day, int _month, int _year, int _hour, int _min, int _sec)
{
    day = _day;
    month = _month;
    year = _year;
    hour = _hour;
    minute = _min;
    second = _sec;
}
DateTime::~DateTime(){
    
}


