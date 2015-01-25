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
            string userName,password, tryAgin="";
            while(ans == false){
                cout << "Login : " << endl << "Username: " << endl;
                cin >> userName;
                cout << "Password: " << endl;
                cin >> password;
                ans = Authenticate(userName, password);
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
            string tmp =_pop3.STAT();
            cout << tmp << endl;
            break;
        }
        case 3:{
            string tmp =_pop3.LIST();
            cout << tmp << endl;
            break;
        }
        case 4:{
            int msgNum;
            cout << "Choose message number:" << endl;
            string tmp =_pop3.RETR(msgNum);
            cout << tmp << endl;
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            break;
        }
        case 7:{
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
}

bool MailInterface::Authenticate(string userName, string passWord){

}

string MailInterface::GetMailStatus(){
    
}

void MailInterface::GetMailList(){
    
}

void MailInterface::GetOneMail(const int mailID){
    
}

void MailInterface::DeleteMail(const int mainID){
    
}

void MailInterface::RSET( ){
    
}

void MailInterface::Quit(){
    
    exit(0);
}

MailInterface::~MailInterface(){
    
}
//check it again