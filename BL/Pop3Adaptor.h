//
//  Pop3Adaptor.h
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#ifndef __pop3__Pop3Adaptor__
#define __pop3__Pop3Adaptor__

#include "Includes.h"
#include "List.h"
#include "MailMessage.h"
#include "User.h"
#include <sstream>
#include <fstream>
#include "DataReader.h"
// This class responsible to fetch and management your mailbox.
// this implemenation will the mail box stoarge will base on a file systems.
// it needs to take all the info from the "user list" and "mail list"

/* steps: first it needs to get the username - it checks if its exist in the user's list, then the password- confirms it with that user password */

class Pop3Adaptor
{
private:
//    int userNum; //the user's number in tje user's container
    DataReader _dataRe;
    User *_user;
    string _result;
    
public:
    /* pop3Adaptor constractor. need the address of the data file*/
    Pop3Adaptor(const char* fileadd):_result(""),_dataRe(fileadd),_user(_dataRe.getUser()){
        ;
        _dataRe.readFromData();
    
    }
    
    /* USER userid
     This must be the first command after the connect.
     Supply your e-mail userid (this may or may not not the full e-mail address).
     Example: USER john.smith
     */
    const char* User(const string userId);
    
    /* PASS password
     This must be the next command after USER.
     Supply your e-mail password.
     The password may be case sensitive.
     */
    const char* PASS (const string password);
    
    /* STAT SPEC
     STAT The response to this is: +OK #msgs #bytes Where #msgs is the number of messages
     in the mail box and #bytes is the total bytes used by all messages.
     Sample response: +OK 3 345910
     */
    const char* STAT ();
    
    /* LIST SPEC
     LIST The response to this lists a line for each message with its
     number and size in bytes, ending with a period on a line by itself. Sample response:
     +OK 3 messages
     1 1205
     2 305
     3 344400
     */
    const char* LIST();
    
    /* RETR SPEC
     This sends message number msg# to you (displays on the Telnet screen).
     You probably don't want to do this in Telnet (unless you have turned on Telnet logging).
     Example: RETR 2 */
    const char* RETR(int msgNumber);
    
    /* DELE msg# SPEC
     This marks message number msg# for deletion from the server.
     This is the way to get rid a problem causing message.
     It is not actually deleted until the QUIT command is issued.
     If you lose the connection to the mail server before issuing the QUIT command,
     the server should not delete any messages. Example: DELE 3 */
    const char* DELE(int msgNumber);
    
    /* RSET SPEC
     This resets (unmarks) any messages previously marked for deletion in this session
     so that the QUIT command will not delete them.
     */
    const char* RSET();
    
    /* QUIT SPEC
     This deletes any messages marked for deletion,
     and then logs you off of the mail server.
     This is the last command to use. 
     This does not disconnect you from the ISP, just the mailbox.
     */
    const char* QUIT();
    
    const char* displaySum();//displays the user all the massages, including those who "marked" for deletion (option 4 in the menu)
    
};
#endif /* defined(__pop3__Pop3Adaptor__) */
