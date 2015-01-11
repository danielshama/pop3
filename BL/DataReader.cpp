//
//  DataReader.cpp
//  pop3
//
//  Created by Daniel Shamama on 1/8/15.
//  Copyright (c) 2015 Daniel Shamama. All rights reserved.
//

#include "DataReader.h"
#include <fstream>


DataReader::DataReader(string dataFile): dataAddres(dataFile){
    readFromData();
}

void DataReader::readFromData(){
    ifstream myData(dataAddres);
    char tmpStr[250];
    int len;
    string _userName,_password;
    bool ifTakeUser = false;
    
    int msgID=0;
    string from,to,msgContent,receivedDate;
    
    
    
    if(myData.is_open()){
        while (myData.getline(tmpStr, 120)) {
            len = (int)strlen(tmpStr);
            if(tmpStr[0] != '#' || len > 1){
                if(ifTakeUser==false){
                    _userName = strtok(tmpStr,", \n");
                    _password = strtok(NULL,", \n");
                    ifTakeUser=true;
                }else {
                    msgID= atoi(strtok(tmpStr,", \n"));
                    from = strtok(NULL,", \n");
                    to = strtok(NULL,", \n");;
                    receivedDate = strtok(NULL,", \n");
                    msgContent = strtok(NULL,"\r\n");
                }
            }
            DateTime tmpDate = calculDateTime(receivedDate);
            
            MailMessage mailMsg(msgID,from,to,msgContent,tmpDate);
            
            Msgs.add(mailMsg);
            
        }
        _users.setUser(_userName, _password);
        
    }
    
    myData.close();
    
    
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
