//
//  DataReader.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/8/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "DataReader.h"
#include <fstream>


DataReader::DataReader(const char* dataFile): dataAddres(dataFile){
}

DataReader::DataReader(const DataReader& o): dataAddres(o.dataAddres),_user(o._user){
}

void DataReader::readFromData(){
    char tmpStr[250];
    int len;
    string _userName,_password;
    bool ifTakeUser = false;
    int msgID=0;
    string from,to,msgContent,receivedDate;
    
    ifstream myData(dataAddres);
    
    
    if(myData.is_open()){
        List<MailMessage> *tmpMsgsList = new List<MailMessage>;
        while (myData.getline(tmpStr, 250)) {
            len = (int)strlen(tmpStr);
            if(tmpStr[0] != '#' && len > 1){
                if(ifTakeUser==false){
                    _userName = strtok(tmpStr,", \n\r");
                    _password = strtok(NULL,", \n\r");
                    _user.setUserName(_userName);
                    _user.setPassword(_password);
                    ifTakeUser=true;
                }else {
                    msgID= atoi(strtok(tmpStr,", \n\r"));
                    from = strtok(NULL,", \n\r");
                    to = strtok(NULL,", \n\r");;
                    receivedDate = strtok(NULL,", \n\r");
                    msgContent = strtok(NULL,"\r\n");
                    
                    DateTime tmpDate = calculDateTime(receivedDate);
                    MailMessage mailMsg(msgID,from,to,msgContent,tmpDate);
                    tmpMsgsList->insert(mailMsg);
                }
            }
        }
        myData.close();
        _user.setMsgList(tmpMsgsList);
    }
    
    
}
//01012013230535

DateTime DataReader::calculDateTime(string time){
    DateTime tmpDateTime;
    int day,month,year,hour,minute,second;
   
    day = (time[0]-'0')*10 + (time[1]-'0');
    month =(time[2]-'0')*10 + (time[3]-'0');
    year = (time[4]-'0')*1000 + (time[5]-'0')*100 + (time[6]-'0')*10 + (time[7]-'0');
    hour = (time[8]-'0')*10 + (time[9]-'0');
    minute =(time[10]-'0')*10 + (time[11]-'0');
    second =(time[12]-'0')*10 + (time[13]-'0');
    
    tmpDateTime.setTime(day, month, year, hour, minute, second);
    return tmpDateTime;
    
}
void DataReader::upDateData(){
    int n =_user.get_mails()->getAmount();
    int *idsTmp = new int[n];
    char line[250];
    ifstream old;
    old.open(dataAddres);
    ofstream temp;
    temp.open("temp.txt");
    int j=0;
    for (int i = 1; i <= n; ++i)
    {
        if(_user.get_mails()->ifForDel(i)){
            idsTmp[j] = _user.get_mails()->getObj(i).getId();
            j++;
        }
    }
    int *ids = new int[j+1];
    for(int u=0 ; u<j+1; u++){
        ids[u]=idsTmp[u];
    }
    delete []idsTmp;
    for( int d=0 ; d<4 ; d++){
        old.getline(line,250);
        temp << line << endl;
    }

    while (old.getline(line,250))
    {
        char tpline[250];
        strcpy(tpline, line);
        bool ifMark = false;
        for(int x=0; x<n; x++){
            int y = atoi(strtok(line," ,"));
            if (y == ids[x])
            {
                ifMark=true;
                break;
            }
        }
        if(ifMark == false){
            temp << tpline << endl;
        }
    }
    temp.close();
    old.close();
    remove(dataAddres.c_str());
    rename("temp.txt",dataAddres.c_str());
    delete []  ids;
    cout << "delete all marks msgs" << endl;
}
User* DataReader::getUser(){
    return &_user;
}

List<MailMessage>* DataReader::getMailBox(int userId){
    return ( _user.get_mails() );
}
