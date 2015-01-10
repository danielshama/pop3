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

string *DataTime::get_time()
{
    string *str = new string();
    if (day < 10)
    {
        str->
    }
}