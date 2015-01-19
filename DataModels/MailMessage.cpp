//
//  MailMessage.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama  & Or Ben David. All rights reserved.
//

#include "MailMessage.h"

string& MailMessage::getMsg()
{
    return data;
}

void MailMessage::set_marked_true()
{
    marked = true;
}

void MailMessage::set_marked_false()
{
    marked = false;
}

bool MailMessage::getMarked()
{
    return marked;
}