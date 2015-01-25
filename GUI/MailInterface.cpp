//
//  MailInterface.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "MailInterface.h"


MailInterface::MailInterface(User tuser):_pop3(&tuser),steps(0),login(false){
}
void MailInterface::runInterFace(){
    int ans=0;
    for (;;steps++){
        
        if(steps==0){
            ans=printMenu(1);
            makeAstep(ans);
            steps++;
        }else{
            if(login == true){
                ans=printMenu(2);
                makeAstep(ans);
            }
        }
        
    }
}
void MailInterface::makeAstep(int act){
    switch (act) {
        case 1:{
            if(login == true){
                cout << "you allredy in" << endl;
                break;
            }
            bool ans = false;
            char* userName;
            char* password;
            string tryAgin="";
            while(ans == false){
                cout << "Login : " << endl << "Username: " << endl;
                cin >> userName;
                cout << "Password: " << endl;
                cin >> password;
                const char* x = userName;
                const char* y = password;
                ans = Authenticate(x, y);
                if(ans == false){
                    while(tryAgin != "y" && tryAgin != "Y"){
                        cout << "Try again? y/n" << endl;
                        cin >> tryAgin;
                        if(tryAgin == "n" || tryAgin == "N") break;
                    }
                }else login =true;
            }
            break;
        }
        case 2:{
            GetMailStatus();
            break;
        }
        case 3:{
            GetMailList();
            break;
        }
        case 4:{
            GetOneMail();
            break;
        }
        case 5:{
            DeleteMail();
            break;
        }
        case 6:{
            RSET();
            break;
        }
        case 7:{
            Quit();
            break;
        }
        default:{
            break;
        }
    }
}
int MailInterface::printMenu(int opt){
    int answer;
    while (opt != 0){
        switch (opt) {
            case 1:
                cout<< "Welcome to My Outlook ( Only Get mails ) : " << endl
                <<"1.	Authenticate. ( User + Password  Commands)" <<endl
                <<"2.	Quit ( Quit Command + Exit the Program )."<<endl;
                
                cin >> answer;
                if ( answer ==1 || answer ==2) return answer;
                break;
            default:
                cout<< "Welcome to My Outlook ( Only Get mails ) : " << endl
                <<" 1.	Authenticate. ( User + Password  Commands)"<< endl
                <<" 2.	Get Mail Status ( Stat Command )."<< endl
                <<" 3.	Get Mails List ( List Command )."<< endl
                <<" 4.	Get One Mail (Retr Command )."<< endl
                <<" 5.	Delete mail ( Dele Command)."<< endl
                <<" 6.	RSET ( RSET Command)."<< endl
                <<" 7.	Quit ( Quit Command + Exit the Program )."<< endl;
                
                cin >> answer;
                if ( answer >=1 || answer <=7) return answer;
                break;
        }
    
    }
    return 1;
}
bool MailInterface::Authenticate(const char* userName, const char* passWord){
    string user =_pop3.User(userName);
    string pass=_pop3.PASS(passWord);
    
    if( user== "+OK" && pass=="+OK"){
        return true;
    }else return false;

}

void MailInterface::GetMailStatus(){
    string tmp =_pop3.STAT();
    cout << tmp << endl;
}

void MailInterface::GetMailList(){
    string tmp=_pop3.STAT(), ok;
    ok.assign(tmp,4,1);
    if(ok == "0"){
        cout<< "Mailbox is empty" << endl;
        return;
    }
    string tmpe =_pop3.LIST();
    cout << tmpe << endl;
}

void MailInterface::GetOneMail(){
    int msgNum;
    string tmp=_pop3.STAT(), ok;
    ok.assign(tmp,4,1);
    if(ok == "0"){
        cout<< "Mailbox is empty" << endl;
        return;
    }
    while(ok != "0"){
        tmp = _pop3.displaySum();
        cout<< tmp << endl;
        cout << "Choose message number:" << endl;
        cin >> msgNum;
        tmp =_pop3.RETR(msgNum);
        if(tmp[0] == '-') {
            cout << "Try again. \n" << endl;
            continue;
        }
        cout << tmp << endl;
        break;
    }
}

void MailInterface::DeleteMail(){
    int msgNum;
    string tmp=_pop3.STAT(), ok;
    ok.assign(tmp,4,1);
    if(ok == "0"){
        cout<< "Mailbox is empty" << endl;
        return;
    }
    while(ok != "0"){
        tmp = _pop3.displaySum();
        cout<< tmp << endl;
        cout << "Choose message number:" << endl;
        cin >> msgNum;
        tmp =_pop3.DELE(msgNum);
        if(tmp[0] == '-') {
            cout << "Try again. \n" << endl;
            continue;
        }
        break;
    }
}

void MailInterface::RSET( ){
    _pop3.RSET();
    cout << "Restart...\n" << endl;
}

void MailInterface::Quit(){
    _pop3.QUIT();
    exit(0);
}

MailInterface::~MailInterface(){
    
}