//
// Created by whd on 2022/12/11.
//

#include "../include/adminOpration.h"
#include "../lib/jsoncpp/json/json.h"
#include "../include/JsonUtil.h"
#include <iostream>
#define RATE 0.3
extern Json::Value station_root;
extern Json::Value order_root;

static void compute(int** stationTickets, int station_number,int seat_number);
static int computeReback(int **stationTickets, int station,int station_number);
static map<int,double> computeRate(int stations);

void computeProfit(){// 计算利润
    float profit = 0;
    Json::Value::Members users = order_root.getMemberNames();
    for(auto & usr : users){
        auto consume = order_root.get(usr,"null");
        for(int i=0; i<consume.size(); i++){
            profit+=consume[i].get("price","0").asFloat();
        }
    }
    std::cout<<"all profit is: "<<profit<<std::endl;
}

void layTickets(){// 放票
    std::string train_No;
    std::cout<<"please input the train No:"<<std::endl;
    std::cin>>train_No;
    Json::Value train_map = station_root.get("train_map","null");
    Json::Value train_tickets = station_root.get("ticket","null").get(train_map.get(train_No,"null").asString(),"null");
    int station_number = station_root.get("train_info","null").get(train_map.get(train_No,"null").asString(),"null").get("station_num","0").asInt();
    int seat_number = station_root.get("train_info","null").get(train_map.get(train_No,"null").asString(),"null").get("seat_num","0").asInt();
    int ** stationTickets = new int*[station_number];
    for(int i=0;i<station_number;i++){
        stationTickets[i] = new int[station_number]{0};
    }

    compute(stationTickets,station_number,seat_number);
    for(int i=0; i<station_number; i++){
        Json::Value i_ticket = train_tickets.get(std::to_string(i+1),"null");
        for(int j=i+1;j<station_number;j++){
            for(int k=0; k<i_ticket.size();k++){
                if(i_ticket.get(k,"null").get("destination","null").asInt()==j+1){
                    i_ticket[k]["number"] = stationTickets[i][j];
                }
            }
        }
        train_tickets[std::to_string(i+1)]=i_ticket;
    }
    station_root["ticket"][train_map.get(train_No,"null").asString()]=train_tickets;
    JsonUtil::writeJsonFile("../data/station.json", station_root);
    std::cout<<"lay tickets finish"<<std::endl;
}

void compute(int** stationTickets, int station_number, int seat_number){
    static map<int, double> rate;
    int remainSeat = seat_number;
    for(int i=0; i<station_number;i++){
        rate = computeRate(station_number-1-i);
        remainSeat+= computeReback(stationTickets,i,station_number);
        int s_t = (int)remainSeat*RATE;
        for(int j=i+1; j<station_number;j++){
            //*((int *)stationTickets+station_number*i+j) = (int)s_t*rate[j-i];
            stationTickets[i][j] = (int)s_t*rate[j-i];
        }
        if((remainSeat-s_t)>0)
            remainSeat = remainSeat-s_t;
        else
            remainSeat = 0;
    }
}

int computeReback(int** stationTickets, int station, int station_number){
    int reback = 0;
    for(int i=0; i<=station;i++){
        //reback+=*((int *)stationTickets+station_number*i+station);
        reback += stationTickets[i][station];
    }
    return reback;
}

map<int,double> computeRate(int n){
    map<int, double> data;
    if(n!=0){
        double b = 0.05;
        double k = 2*(1-n*b)/(n*(n+1));
        for(int i=0; i<n;i++){
            data[i+1]=k*(i+1)+b;
        }
    }
    return data;
}