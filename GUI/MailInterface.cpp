//
//  MailInterface.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/6/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "MailInterface.h"


MailInterface::MailInterface(DataReader* _dr):_pop3(_dr),_dataReader(*_dr),steps(0),login(false){
}
void MailInterface::runInterFace(){
    int ans=0;
    for (;;){
        
        if(steps==0){
            ans=printMenu(1);
            if(ans==1)makeAstep(ans);
            else Quit();
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
                cout << "you allredy in.\n" << endl;
                break;
            }
            bool ans = false;
            string userName;
            string password;
            string tryAgin="";
            while(ans == false){
                cout << "\nLog in - " << endl << " Username: ";
                cin >> userName;
                cout << " Password: ";
                cin >> password;
                const string x = userName;
                const string y = password;
                ans = Authenticate(x, y);
                if(ans == false){
                    cout << "Try again? y/n" << endl;
                    while(tryAgin==""){
                        cin >> tryAgin;
                    }
                    if(tryAgin == "y" || tryAgin == "Y"){
                        makeAstep(1);
                    }else break;
                }else{
                    if(userName.find("@")!=string::npos){
                        int loc =(int)userName.find("@");
                        userName.erase(loc);
                    }
                    cout << "\n\n Hello " << userName << "," << endl;
                   login =true;
                    
                }
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
    int answer=0;
    while (opt != 0){
        switch (opt) {
            case 1:
                cout<< "\n\nWelcome to My Outlook ( Only Get mails ) : " << endl
                <<"1.	Authenticate." <<endl
                <<"2.	Quit ( Exit the Program )."<<endl
                <<"\nYour choise: ";
                while(answer==0){
                    cin >> answer;
                }
                if ( answer ==1 || answer ==2) return answer;
                break;
            default:
               // cout << "Hello " <<
                cout<< "\n\nWelcome to My Outlook ( Only Get mails ) : " << endl
                <<" 1.	Get Mailbox Status."<< endl
                <<" 2.	Print Mails List."<< endl
                <<" 3.	Print One Mail."<< endl
                <<" 4.	Delete one mail."<< endl
                <<" 5.	Reset."<< endl
                <<" 6.	Quit ( Exit the Program )."<< endl
                <<"\nYour choise: ";
                
                cin >> answer;
                if ( answer >=1 || answer <=6) return answer+1;
                break;
        }
    
    }
    return 1;
}
bool MailInterface::Authenticate(const string userName, const string passWord){
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
        cout << "Choose message number:";
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